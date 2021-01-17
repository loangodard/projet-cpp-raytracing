#ifndef SCENE_H
#define SCENE_H
#include "shape.h"
#include "sphere.h"
#include "ray3f.h"
#include "quad.h"
#include <vector> 

/**
 * @brief Scene
 * 
 */
class Scene{
    private:
    /**
     * @brief Normalement on attendait une liste des formes comprennant à la fois plans et spheres mais par soucis technique on a divisé les formes en deux listes
     * 
     */
        std::vector<Quad> plans;
        std::vector<Sphere> shapes;
        Vector3f source; //Coordonnées de la lumière
        float intensite; //Intensite de la lumière
        Vector3f camera; //Position de la caméra
    public:
    /**
     * @brief Construct a new Scene object
     * 
     * @param source_ 
     * @param camera_ 
     */
        Scene(const Vector3f& source_,const Vector3f& camera_,float intensite_);

        /**
         * @brief ajout d'une sphère à la scène
         * 
         * @param s 
         */
        void addSphere(const Sphere &s);

        /**
         * @brief Ajout d'un plan (Quad) à la scène
         * 
         * @param q 
         */
        void addQuad(const Quad &q);

        /**
         * @brief Get the source object
         * 
         * @return Vector3f 
         */
        Vector3f get_source();

        /**
         * @brief Get the camera object
         * 
         * @return Vector3f 
         */
        Vector3f get_camera();

        /**
         * @brief Get the intensite object
         * 
         * @return float 
         */
        float get_intensite(){return intensite;};

        /**
         * @brief Renvoi un booléen en fonction de s'il y a intersection entre le rayon et une forme de la scène ou non. Modifie également par référence
         *  P,N, et t_r qui permettent ensuite de calculer l'intensité de la lumière au point courant.
         * 
         * @param r 
         * @param P 
         * @param N 
         * @param s
         * @param t_r
         * @return true 
         * @return false 
         */
        bool is_hit_global(const Ray3f &r,Vector3f & P, Vector3f & N,Shape & s,float &t_r);

        /**
         * @brief Renvoi la couleur du pixel à écrire. Cette fonction est recursive et nbRebonds détermine le nombre maximal de rebonds.
         *        get_pixel_color gère les surfaces réfléchis.
         * 
         * @param r 
         * @param nbRebonds 
         * @return Vector3f 
         */
        Vector3f get_pixel_color(const Ray3f & r,int nbRebonds);

        /**
         * @brief Renvoi la forme d'indice i
         * 
         * @param i 
         * @return Shape 
         */
        Shape operator[](int i);

        /**
         * @brief Rend la scène et génère l'image de sortie
         * 
         * @param width 
         * @param height 
         * @param filename 
         */
        void render(int width, int height, std::string filename);
};

#endif