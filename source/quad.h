#ifndef QUAD_H
#define QUAD_H
#include "shape.h"
#include "vector3f.h"

class Quad : public Shape{
    private:
        Vector3f origin;
        Vector3f width;
        Vector3f height;
    public:
        Quad(Vector3f origin_, Vector3f width_, Vector3f height_,Material mat_);
        bool is_hit(const Ray3f &r,Vector3f & P, Vector3f & N,float &t) const;
};

#endif