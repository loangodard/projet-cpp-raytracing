#include "scene.h"

Scene::Scene(const Vector3f& source_,const Vector3f& camera_){
    source = source_;
    camera = camera_;
}

void Scene::addSphere(const Sphere &s){
    shapes.push_back(s);
}

void Scene::addQuad(const Quad &q){
    plans.push_back(q);
}

Vector3f Scene::get_source(){
    return source;
}

Vector3f Scene::get_camera(){
    return camera;
}

bool Scene::is_hit_global(const Ray3f &r,Vector3f & P, Vector3f & N,Shape & s){
    bool is_hit_global = false;
    float min_t = 1E100;
    //on check les intersections avec les plans
    for(int i = 0; i < plans.size(); i++){
        Vector3f P_courant,N_courant;
        float t;
        bool is_hit_courant = plans[i].is_hit(r,P_courant,N_courant,t);
        if (is_hit_courant){
            is_hit_global = true;
            if(t<min_t){
                s=plans[i];
                min_t = t;
                P=P_courant;
                N=N_courant;
            }
        }
    }

    //on check ensuite s'il y a des intersections avec des sphères
    for(int i = 0; i < shapes.size(); i++){
        Vector3f P_courant,N_courant;
        float t;
        bool is_hit_courant = shapes[i].is_hit(r,P_courant,N_courant,t);
        if (is_hit_courant){
            is_hit_global = true;
            if(t<min_t){
                s=shapes[i];
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