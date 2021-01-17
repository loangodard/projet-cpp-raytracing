#ifndef SPHERE_H
#define SPHERE_H
#include "shape.h"
#include "vector3f.h"

/**
 * @brief Class permettant d'implémenter les sphères
 * 
 * Sphere hérite de Shape
 * 
 */
class Sphere : public Shape{
    private:
    /**
     * @brief Origine et rayon de la sphère
     * 
     */
        Vector3f origin;
        float radius;
    public:
        /**
         * @brief Construct a new Sphere object
         * 
         * @param origin_ 
         * @param radius_ 
         * @param mat 
         */
        Sphere(Vector3f origin_,float radius_,Material mat);

        /**
         * @brief Renvoi un booléen en fonction de s'il y a intersection entre le rayon et la sphère ou non. Modifie également par référence
         *  P,N, et t qui permettent ensuite de calculer l'intensité de la lumière au point courant.
         * 
         * 
         * @param ray Rayon
         * @param P Point d'intersection
         * @param N Normale à la sphère au point d'intersection
         * @param t 
         * @return true 
         * @return false 
         */
        bool is_hit(Ray3f ray, Vector3f& P,Vector3f& N,float& t) const;

        /**
         * @brief Get the mat object
         * 
         * @return Material 
         */
        Material get_mat();
};

#endif