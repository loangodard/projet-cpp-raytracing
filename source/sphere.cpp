#include "sphere.h"

Sphere::Sphere(Vector3f origin_,float radius_,Material mat) : Shape(mat),origin(origin_),radius(radius_){};

bool Sphere::is_hit(Ray3f ray, Vector3f& P,Vector3f& N, float& t) const{ //Pour le calcul de l'éclairage, on donne pour modifier le point P d'intersection et la normale au point P
    float a = 1;
    float b = 2*(ray.get_direction()*(ray.get_origin()-origin));
    float c = norme(ray.get_origin()-origin)*norme(ray.get_origin()-origin)-radius*radius;
    float discriminant = b*b-4*a*c;
    
    if(discriminant < 0) return false;
    //Si non, la sphère est peut être derrière la caméra, on doit vérifier la valeur des solutions
    float t1,t2;
    t1 = (-b-sqrt(discriminant))/(2*a);
    t2 = (-b+sqrt(discriminant))/(2*a);
    if(t2 < 0){ //On test t2 car il est plus grand que t1
        return false;
    }

    if(t1 > 0){
        t = t1;
    }else{
        t = t2;
    }

    P = ray.get_origin() + t*ray.get_direction();
    N = get_normalized(P-origin); 
    return true;
}