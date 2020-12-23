#include "material.h"

Material::Material(float r, float g, float b, float shininess) : r(r),g(g),b(b),shininess(shininess) {}

Material::Material(Material const & m){
    r = m.get_r();
    g = m.get_g();
    b = m.get_b();
    shininess = m.get_shininess();
}

float Material::get_r() const{
    return r;
}
float Material::get_g() const{
    return g;
}
float Material::get_b() const{
    return b;
}
float Material::get_shininess() const{
    return shininess;
}