#include "scene.h"
#include "utils.h"

Scene::Scene(const Vector3f &source_, const Vector3f &camera_, float intensite_)
{
    source = source_;
    camera = camera_;
    intensite = intensite_;
}

void Scene::addSphere(const Sphere &s)
{
    shapes.push_back(s);
}

void Scene::addQuad(const Quad &q)
{
    plans.push_back(q);
}

Vector3f Scene::get_source()
{
    return source;
}

Vector3f Scene::get_camera()
{
    return camera;
}

bool Scene::is_hit_global(const Ray3f &r, Vector3f &P, Vector3f &N, Shape &s, float &t_r)
{
    bool is_hit_global = false;
    float min_t = 1E100;
    //on check les intersections avec les plans
    for (int i = 0; i < plans.size(); i++)
    {
        Vector3f P_courant, N_courant;
        float t;
        bool is_hit_courant = plans[i].is_hit(r, P_courant, N_courant, t);
        if (is_hit_courant)
        {
            is_hit_global = true;
            if (t < min_t)
            {
                s = plans[i];
                min_t = t;
                P = P_courant;
                N = N_courant;
            }
        }
    }

    //on check ensuite s'il y a des intersections avec des sphères
    for (int i = 0; i < shapes.size(); i++)
    {
        Vector3f P_courant, N_courant;
        float t;
        bool is_hit_courant = shapes[i].is_hit(r, P_courant, N_courant, t);
        if (is_hit_courant)
        {
            is_hit_global = true;
            if (t < min_t)
            {
                s = shapes[i];
                min_t = t;
                P = P_courant;
                N = N_courant;
            }
        }
    }
    t_r = min_t;
    return is_hit_global;
};

Vector3f Scene::get_pixel_color(const Ray3f &ray, int nbRebonds)
{
    Vector3f P, N;            //Point d'intersection et Normale au point d'intersection (entre rayon et sphère)
    Vector3f intensite_pixel; //Intensité lumineuse de pixel courant

    Shape hitted_shape = Shape(Material(0, 0, 0, 0)); //Initialisation d'une variable qui fera référence à la forme pointé pour récupérer les couleurs
    float t_r;
    if (this->is_hit_global(ray, P, N, hitted_shape, t_r))
    {

        if (hitted_shape.get_material().get_shininess() > 0 && nbRebonds > 0)
        { //si la brillance est supérieur à 0, c'est un miroir
            Vector3f direction_reflechi = ray.get_direction() - 2 * (N * ray.get_direction()) * N;
            Ray3f rayon_reflechi = Ray3f(P + 0.1 * N, direction_reflechi); //On décole un peu le point de la surface pour l'imprecision numérique
            return hitted_shape.get_material().get_shininess() * get_pixel_color(rayon_reflechi, nbRebonds - 1);
        }
        else
        {
            Ray3f test_lum = Ray3f(P + 0.01 * N, get_normalized(source - P)); //Rayon que l'on renvoit vers la lumière pour tester s'il ya des objets entre le point et la lumière
            //On décolle un peu le point pour éviter les erreurs de calculs qui entraine une image taché de points noirs

            Vector3f P_test_lum, N_test_lum;
            Shape hitted_shape_test_lum = Shape(Material(0, 0, 0, 0));
            float t_lum;
            bool is_hit_light = this->is_hit_global(test_lum, P_test_lum, N_test_lum, hitted_shape_test_lum, t_lum);

            if (is_hit_light && t_lum < norme(this->get_source() - P_test_lum))
            {
                intensite_pixel = Vector3f(0, 0, 0);
            }
            else
            {
                Vector3f s_color = Vector3f(hitted_shape.get_material().get_r(), hitted_shape.get_material().get_g(), hitted_shape.get_material().get_b());
                intensite_pixel = (((intensite * get_normalized((this->get_source() - P)) * N) / (norme(this->get_source() - P) * norme(this->get_source() - P)))) * s_color;
            }

            int r = min(255, max(0, intensite_pixel.get_x())); //Valeurs entre 0 et 255
            int g = min(255, max(0, intensite_pixel.get_y()));
            int b = min(255, max(0, intensite_pixel.get_z()));
            return Vector3f(r, g, b);
        }
    }
    else
    {
        return Vector3f(0, 0, 0);
    }
}

Shape Scene::operator[](int i)
{
    return shapes[i];
}

void Scene::render(int width, int height, std::string filename)
{
    /** Initialisation de la sortie **/
    float fov = 60 * M_PI / 100; //Champ visuel horizontal (60°) convertit en rad
    std::cout << "Initialisation de l'image au format png, taille : " << width << "x" << height << " px;" << std::endl;

    //Initialisation des buffers
    float *R = (float *)malloc(width * height * sizeof(float));
    float *G = (float *)malloc(width * height * sizeof(float));
    float *B = (float *)malloc(width * height * sizeof(float));
    //Initialisation de l'image
    png_bytep img_info = NULL;
    img_info = (png_bytep)malloc(3 * width * height * sizeof(png_byte));
    FILE *fp = NULL;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    char *title = strdup(filename.c_str());
    char *desc = strdup("Projet C++");
    initImage(title, width, height, desc, fp, png_ptr, info_ptr);
    /** Fin de l'initialisation de la sortie **/

    int xPos, yPos;
    // Écriture de l'image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // On normalise la direction pour simplifier les calculs dans is_hit.
            Vector3f direction = get_normalized(Vector3f(j - width / 2, i - height / 2, -width / (2 * tan(fov / 2))));
            Ray3f ray = Ray3f(this->get_camera(), direction);
            Vector3f color = this->get_pixel_color(ray, 5);
            write_pixel(R, G, B, height - i - 1, j, color.get_x(), color.get_y(), color.get_z(), width);
        }
    }

    //Sauvegarde de l'image
    printf("Saving PNG\n");
    writeImage(png_ptr, R, G, B, width, height, fp, info_ptr);

    // Libération des buffers
    free(R);
    free(G);
    free(B);
}