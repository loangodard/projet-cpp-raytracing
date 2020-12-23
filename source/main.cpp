#include "vector3f.h"
#include "ray3f.h"
#include "camera.h"
#include "material.h"
#include "shape.h"
#include "sphere.h"

#include <png.h>

// c++ material.cpp shape.cpp sphere.cpp vector3f.cpp ray3f.cpp main.cpp 

int main(){
    Sphere s = Sphere(Vector3f(0,0,-13),12.9,Material(1,2,3,10));
    Sphere s2 = Sphere(Vector3f(30,30,-6),1,Material(1,2,3,10));
    std::cout<<s.is_hit(Ray3f(Vector3f(0,0,0), Vector3f(1,1,1)))<<std::endl;

    int width = 151;
    int height = 151;

    for(int i = 0; i < height;i++){
        for(int j = 0; j < width; j++){
            // std::cout<<'('<<-floor(width/2)+j<<';'<<floor(height/2)-i<<')' ; Cas W,H impaires
            if(s.is_hit(Ray3f(Vector3f(0,0,0), Vector3f(-floor(width/2)+j,floor(height/2)-i,-2)))){
                std::cout<<1;
            }
            else if(s2.is_hit(Ray3f(Vector3f(0,0,0), Vector3f(-floor(width/2)+j,floor(height/2)-i,-2)))){
                std::cout<<2;
            }else{
                std::cout<<0;
            }
            
            // std::cout<<'('<<-width/2+j+1<<';'<<height/2-i-1<<')' ; Cas W,H Paire
        }
        std::cout<<std::endl; 
    }

    return 0;
}