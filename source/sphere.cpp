#include "sphere.h"

Sphere::Sphere(Vector3f origin_,float radius_,Material mat) : Shape(mat),origin(origin_),radius(radius_){};

bool Sphere::is_hit(Ray3f ray) const{
    float a = norme(ray.get_direction())*norme(ray.get_direction());
    float b = 2*(ray.get_direction()*(ray.get_origin()-origin));
    float c = norme(ray.get_origin()-origin)*norme(ray.get_origin()-origin)-radius*radius;

    float discriminant = b*b-4*a*c;

    if(discriminant >= 0){
        return true;
    }
    return false;
}