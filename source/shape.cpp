#include "shape.h"

Shape::Shape(Material mat): matter(mat){}

Material Shape::get_material() const{
     return matter;
};