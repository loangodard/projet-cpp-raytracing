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
    // Sphere s2 = Sphere(Vector3f(30, 20, -60), 20.3, Material(255, 255, 255, 10));
    Sphere s3 = Sphere(Vector3f(-20, -20, -55), 20, Material(255, 255, 255, 10));

    Quad plan = Quad(Vector3f(0, 0, -70), Vector3f(1, 0, 0), Vector3f(0, 1, 0), Material(1, 2, 3, 10));
    float d1;
    Quad plan2 = Quad(Vector3f(0, -70, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(1, 2, 3, 10));
    float d2;
    Quad plan3 = Quad(Vector3f(0, 70, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(1, 2, 3, 10));
    float d3;

    Scene s;
    s.addSphere(s1);
    s.addSphere(s3);
    //Création de la lumière
    Vector3f source = Vector3f(-15, 60, -30);
    float intensite = 6000;
    Vector3f P, N;            //Point d'intersection et Normale au point d'intersection (entre rayon et sphère)
    Vector3f intensite_pixel; //Intensité lumineuse de pixel courant
    //Fin de l'initialisation du monde

    // Initialisation de la sortie
    int width = 1024;
    int height = 1024;
    float fov = 60 * M_PI / 100; //Champ visuel horizontal (60°) convertit en rad
    std::cout << "Initialisation de l'image au format png, taille : " << width << "x" << height << " px;" << std::endl;
    float *R = (float *)malloc(width * height * sizeof(float));
    float *G = (float *)malloc(width * height * sizeof(float));
    float *B = (float *)malloc(width * height * sizeof(float));
    png_bytep img_info = NULL;
    img_info = (png_bytep)malloc(3 * width * height * sizeof(png_byte));
    FILE *fp = NULL;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    initImage("result.png", width, height, "Projet C++", fp, png_ptr, info_ptr);
    //Fin de l'initialisation de la sortie

    int xPos, yPos;
    // Écriture de l'image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // On normalise la direction pour simplifier les calculs dans is_hit.
            Vector3f direction = get_normalized(Vector3f(j - width / 2, i - height / 2, -width / (2 * tan(fov / 2))));
            Ray3f ray = Ray3f(Vector3f(0, 0, 0), direction);
            if (s.is_hit_global(ray, P, N))
            {
                Vector3f s_color = Vector3f(255, 1, 0);
                intensite_pixel = s_color * (((intensite * get_normalized((source - P)) * N) / (norme(source - P) * norme(source - P))));
                int r = min(255, max(0, intensite_pixel.get_x())); //Pour avoir des valeurs entre 0 et 255
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
