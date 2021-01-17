#include "vector3f.h"
#include "ray3f.h"
#include "camera.h"
#include "material.h"
#include "shape.h"
#include "sphere.h"
#include "writing_png.h"
#include "quad.h"
#include "scene.h"
#include <png.h>

// g++ material.cpp shape.cpp sphere.cpp vector3f.cpp ray3f.cpp main.cpp writing_png.cpp quad.cpp utils.cpp scene.cpp -lpng -lz;

int main()
{
    //Initialisation de la scène
    Sphere s1 = Sphere(Vector3f(0, 0, -55), 20, Material(255, 255, 255, 10));
    Sphere s2 = Sphere(Vector3f(-30, 0, -50), 10, Material(0, 0, 255, 10));
    Sphere s3 = Sphere(Vector3f(30, 0, -50), 10, Material(255, 0, 0, 10));

    Quad plan = Quad(Vector3f(0, 0, -90), Vector3f(1, 0, 0), Vector3f(0, 1, 0), Material(255, 65, 156, 10));
    Quad plan2 = Quad(Vector3f(0, -70, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(89, 210, 89, 10));
    Quad plan3 = Quad(Vector3f(0, 90, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(255, 255, 255, 10));
    Quad plan4 = Quad(Vector3f(-80, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1), Material(255, 0, 0, 10));  // Gauche
    Quad plan5 = Quad(Vector3f(80, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1), Material(255, 0, 255, 10)); // droite
    //création de la lumière
    Vector3f source = Vector3f(60, 95, -25);
    Vector3f camera = Vector3f(0, 0, 10);

    Scene s = Scene(source, camera);
    s.addSphere(s1);
    s.addSphere(s2);
    s.addSphere(s3);
    s.addQuad(plan);
    s.addQuad(plan2);
    s.addQuad(plan3);
    s.addQuad(plan4);
    s.addQuad(plan5);

    float intensite = 10000;
    Vector3f P, N;            //Point d'intersection et Normale au point d'intersection (entre rayon et sphère)
    Vector3f intensite_pixel; //Intensité lumineuse de pixel courant
    //Fin de l'initialisation du monde

    // Initialisation de la sortie
    int width = 1000;
    int height = 1000;
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
    char *title = strdup("result.png");
    char *desc = strdup("Projet C++");
    initImage(title, width, height, desc, fp, png_ptr, info_ptr);
    //Fin de l'initialisation de la sortie

    int xPos, yPos;
    // Écriture de l'image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // On normalise la direction pour simplifier les calculs dans is_hit.
            Vector3f direction = get_normalized(Vector3f(j - width / 2, i - height / 2, -width / (2 * tan(fov / 2))));
            Ray3f ray = Ray3f(s.get_camera(), direction);
            Shape hitted_shape = Shape(Material(0, 0, 0, 0)); //Initialisation d'une variable qui fera référence à la forme pointé pour récupérer les couleurs
            float t_r;
            if (s.is_hit_global(ray, P, N, hitted_shape,t_r))
            {

                Ray3f test_lum = Ray3f(P+0.01*N, get_normalized(source - P)); //Rayon que l'on renvoit vers la lumière pour tester s'il ya des objets entre le point et la lumière
                //On décolle un peu le point pour éviter les erreurs de calculs qui entraine une image taché de points noirs

                Vector3f P_test_lum, N_test_lum;
                Shape hitted_shape_test_lum = Shape(Material(0, 0, 0, 0));
                float t_lum;
                bool is_hit_light = s.is_hit_global(test_lum, P_test_lum, N_test_lum, hitted_shape_test_lum,t_lum);

                if (is_hit_light && t_lum < norme(s.get_source() - P_test_lum))
                {
                    intensite_pixel = Vector3f(0,0,0);
                }else{
                    Vector3f s_color = Vector3f(hitted_shape.get_material().get_r(), hitted_shape.get_material().get_g(), hitted_shape.get_material().get_b());
                    intensite_pixel = (((intensite * get_normalized((s.get_source() - P)) * N) / (norme(s.get_source() - P) * norme(s.get_source() - P)))) * s_color;
                }

                int r = min(255, max(0, intensite_pixel.get_x())); //Valeurs entre 0 et 255
                int g = min(255, max(0, intensite_pixel.get_y()));
                int b = min(255, max(0, intensite_pixel.get_z()));
                write_pixel(R, G, B, height - i - 1, j, r, g, b, width);
            }
            else
            {
                write_pixel(R, G, B, height - i - 1, j, 0, 0, 0, width);
            }
        }
    }

    //Sauvegarde de l'image
    printf("Saving PNG\n");
    writeImage(png_ptr, R, G, B, width, height, fp, info_ptr);

    // Libération des buffers
    free(R);
    free(G);
    free(B);

    return 1;
}
