#include "quad.h"

// g++ quad.cpp shape.cpp material.cpp vector3f.cpp ray3f.cpp

Quad::Quad(Vector3f origin_, Vector3f width_, Vector3f height_,Material mat_) : Shape(mat_),origin(origin_),width(width_),height(height_) {};

bool Quad::is_hit(Ray3f ray,float &d) const
{ 
    Vector3f n = get_normalized(vectoriel(width,height));

    float denom = n*ray.get_direction();
    
    if (sqrt(denom*denom) > 0.0000001) { //abs(denom > epsilon)
        Vector3f p0l0 = origin - ray.get_origin();
        float t = (p0l0*n) / denom;
        d = norme(t*ray.get_direction());
        // std::cout << "t = " << t <<std::endl;
        return (t >= 0);
    }
    return false; 
} 