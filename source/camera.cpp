#include "camera.h"

Camera::Camera(Vector3f position_ ,Vector3f direction_) : position(position_), direction(direction_){}

Vector3f Camera::get_position() const{
    return position;
}
Vector3f Camera::get_direction() const{
    return direction;
}