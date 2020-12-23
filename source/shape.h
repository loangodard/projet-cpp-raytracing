#ifndef SHAPE_H
#define SHAPE_H
#include "material.h"
#include "ray3f.h"

class Shape{
    private:
        Material matter;  
    public:
        Shape(Material mat);
        Material get_material() const;
        Ray3f reflect(Ray3f ray) const;
        bool is_hit(Ray3f ray) const;
};

#endif