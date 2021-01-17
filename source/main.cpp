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
    Sphere s1 = Sphere(Vector3f(0, 0, -55), 20, Material(255, 255, 255, 1)); //Sphère blanche réfléchissante de rayon 20.
    Sphere s2 = Sphere(Vector3f(-30, 0, -50), 10, Material(0, 0, 255, 0)); //Sphère bleue diffuse de rayon 10
    Sphere s3 = Sphere(Vector3f(30, 0, -50), 10, Material(255, 0, 0, 0));

    Quad plan = Quad(Vector3f(0, 0, -90), Vector3f(1, 0, 0), Vector3f(0, 1, 0), Material(255, 65, 156, 0));
    Quad plan2 = Quad(Vector3f(0, -70, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(89, 210, 89, 0)); // Fond
    Quad plan3 = Quad(Vector3f(0, 90, 0), Vector3f(0, 0, 1), Vector3f(1, 0, 0), Material(255, 255, 255, 0));
    Quad plan4 = Quad(Vector3f(-80, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1), Material(255, 0, 0, 0));  // Gauche
    Quad plan5 = Quad(Vector3f(80, 0, 0), Vector3f(0, 1, 0), Vector3f(0, 0, 1), Material(255, 0, 255, 0)); // droite
    //création de la lumière
    Vector3f source = Vector3f(60, 95, -25);
    Vector3f camera = Vector3f(0, 0, 10);

    Scene s = Scene(source, camera,10000);
    s.addSphere(s1);
    s.addSphere(s2);
    s.addSphere(s3);
    s.addQuad(plan);
    s.addQuad(plan2);
    s.addQuad(plan3);
    s.addQuad(plan4);
    s.addQuad(plan5);

    std::string filename = "out.png";

    s.render(1000,1000,filename);
    
    return 1;
}
