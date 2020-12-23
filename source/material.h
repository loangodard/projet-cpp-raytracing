#ifndef MATERIAL_H
#define MATERIAL_H

class Material{
    private:
        float r,g,b;
        float shininess;
    public:
        Material(Material const & m);
        Material(float r, float g, float b, float shininess);
        float get_r() const;
        float get_g() const;
        float get_b() const;
        float get_shininess() const; 
};

#endif