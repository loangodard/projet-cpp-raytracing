#include "scene.h"

void Scene::addSphere(const Sphere &s){
    shapes.push_back(s);
}

bool Scene::is_hit_global(const Ray3f &r,Vector3f & P, Vector3f & N){
    bool is_hit_global = false;
    float min_t = 1E100;
    for(int i = 0; i < shapes.size(); i++){
        Vector3f P_courant,N_courant;
        float t;
        bool is_hit_courant = shapes[i].is_hit(r,P_courant,N_courant,t);
        if (is_hit_courant){
            is_hit_global = true;
            if(t<min_t){
                min_t = t;
                P=P_courant;
                N=N_courant;
            }
        }
    }
    return is_hit_global;
};

Shape Scene::operator[](int i){
    return shapes[i];
}