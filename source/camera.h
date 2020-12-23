#include "vector3f.h"
#ifndef CAMERA_H
#define CAMERA_H

class Camera{
    private:
        Vector3f position;
        Vector3f direction;
    public:
        Camera(Vector3f position_, Vector3f direction_);
        Vector3f get_position() const;
        Vector3f get_direction() const;
};

#endif