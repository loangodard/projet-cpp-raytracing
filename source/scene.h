#ifndef SCENE_H
#define SCENE_H
#include "shape.h"
#include "sphere.h"
#include "ray3f.h"
#include "quad.h"
#include <vector> 

class Scene{
    private:
        std::vector<Quad> plans;
        std::vector<Sphere> shapes;
        Vector3f source;
        Vector3f camera;
    public:
        Scene(const Vector3f& source_,const Vector3f& camera_);
        void addSphere(const Sphere &s);
        void addQuad(const Quad &q);
        Vector3f get_source();
        Vector3f get_camera();
        bool is_hit_global(const Ray3f &r,Vector3f & P, Vector3f & N,Shape & s);
        Shape operator[](int i);
};

#endif