#include "quad.h"

// g++ quad.cpp shape.cpp material.cpp vector3f.cpp ray3f.cpp

Quad::Quad(Vector3f origin_, Vector3f width_, Vector3f height_,Material mat_) : Shape(mat_),origin(origin_),width(width_),height(height_) {};

bool Quad::is_hit(const Ray3f &r,Vector3f & P, Vector3f & N,float &t) const
{ 
    N = get_normalized(vectoriel(width,height));

    float denom = N*r.get_direction();
    
    if (sqrt(denom*denom) > 0.0000001) {
        Vector3f p0l0 = origin - r.get_origin();
        t = (p0l0*N) / denom;
        P = r.get_origin() + t*r.get_direction();
        return (t >= 0);
    }
    return false; 
} 