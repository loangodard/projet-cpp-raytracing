#include "ray3f.h"

Ray3f::Ray3f(Vector3f origin_ ,Vector3f direction_) : origin(origin_), direction(direction_){}

Vector3f Ray3f::get_origin() const{
    return origin;
}
Vector3f Ray3f::get_direction() const{
    return direction;
}