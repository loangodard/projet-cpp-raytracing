#ifndef SPHERE_H
#define SPHERE_H
#include "shape.h"
#include "vector3f.h"

class Sphere : public Shape{
    private:
        Vector3f origin;
        float radius;
    public:
        Sphere(Vector3f origin_,float radius_,Material mat);
        bool is_hit(Ray3f ray) const;
};

#endif