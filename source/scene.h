#ifndef SCENE_H
#define SCENE_H
#include "shape.h"
#include "sphere.h"
#include "ray3f.h"
#include <vector> 

class Scene{
    private:    
        std::vector<Sphere> shapes;
    public:
        Scene(){};
        void addSphere(const Sphere &s);
        bool is_hit_global(const Ray3f &r,Vector3f & P, Vector3f & N);
        Shape operator[](int i);
};

#endif