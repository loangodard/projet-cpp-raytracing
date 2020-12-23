#include "vector3f.h"
#ifndef RAY3F_H
#define RAY3F_H

class Ray3f{
    private:
        Vector3f origin;
        Vector3f direction;
    public:
        Ray3f(Vector3f origin_, Vector3f direction_);
        Vector3f get_origin() const;
        Vector3f get_direction() const;
};

#endif