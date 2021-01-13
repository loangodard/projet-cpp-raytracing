#include "vector3f.h"
#include "ray3f.h"
#include "camera.h"
#include "material.h"
#include "shape.h"
#include "sphere.h"
#include "writing_png.h"
#include "quad.h"

#include <png.h>

// g++ material.cpp shape.cpp sphere.cpp vector3f.cpp ray3f.cpp main.cpp writing_png.cpp quad.cpp -lpng -lz;

int main()
{
    // std::cout  << "----->" << getIntFromColor(255,0,0) <<std::endl;

    Sphere s = Sphere(Vector3f(0, 0, -2), 1.999, Material(1, 2, 3, 10));
    Sphere s2 = Sphere(Vector3f(10, 10, -2), 1.999, Material(1, 2, 3, 10));

    Quad plan = Quad(Vector3f(0, 0, -4), Vector3f(1, 0, 0), Vector3f(0, 1, 0), Material(1, 2, 3, 10));
    float d1;
    Quad plan2 = Quad(Vector3f(0, -4, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(1, 2, 3, 10));
    float d2;
    Quad plan3 = Quad(Vector3f(0, 6, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(1, 2, 3, 10));
    float d3;

    Vector3f source = Vector3f(10, 10, -1.8);

    int width = 501;
    int height = 501;

    // Create a test image - in this case a Mandelbrot Set fractal
    // The output is a 1D array of floats, length: width * height
    printf("Creating Image\n");

    float *buffer = (float *)malloc(width * height * 3 * sizeof(float));

    png_bytep img_info = NULL;
    img_info = (png_bytep)malloc(3 * width * height * sizeof(png_byte)); //<=> row

    FILE *fp = NULL;
    png_structp png_ptr = NULL;
    png_infop info_ptr = NULL;
    initImage("result.png",width,height, "Projet C++",fp,png_ptr,info_ptr);

    int xPos, yPos;

    // écriture de l'image
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {
            Ray3f ray = Ray3f(Vector3f(0, 0, 0), Vector3f(-floor(width / 2) + j, floor(height / 2) - i, -2));

            bool isHit1 = plan.is_hit(ray, d1);
            bool isHit2 = plan2.is_hit(ray, d2);
            bool isHit3 = plan3.is_hit(ray, d3);
            std::cout << d1 << " " << d2 << " " << d3 << std::endl;

            if (s.is_hit(Ray3f(Vector3f(0, 0, 0), Vector3f(-floor(width / 2) + j, floor(height / 2) - i, -2))))
            {
                buffer[i * width + j] = 0.2;
            }
            // else if(s2.is_hit(Ray3f(Vector3f(0,0,0), Vector3f(-floor(width/2)+j,floor(height/2)-i,-2)))){
            //     std::cout<<2;
            //     buffer[i * width + j] = 0.5;
            // }

            else if (isHit2)
            {
                write_pixel(buffer,i,j,255,0,255,width);
            }
            else if (isHit3)
            {
                write_pixel(buffer,i,j,255,255,255,width);
            }
            else if (isHit1 && d1 < d3)
            {
                write_pixel(buffer,i,j,0,0,255,width);
            }
            else
            {
                write_pixel(buffer,i,j,0,0,0,width);
            }
        }
    }


    // Save the image to a PNG file
    // The 'title' string is stored as part of the PNG file
    printf("Saving PNG\n");
    writeImage(png_ptr,buffer,width,height,fp,info_ptr);

    // Free up the memorty used to store the image
    free(buffer);

    return 1;
}
