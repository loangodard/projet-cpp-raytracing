#ifndef QUAD_H
#define QUAD_H
#include "shape.h"
#include "vector3f.h"

/**
 * @brief Plans
 * 
 */
class Quad : public Shape{
    private:
    /**
     * @brief Origin du plan, vecteurs "directeurs" de la largeur et hauteur du plan
     * 
     */
        Vector3f origin;
        Vector3f width;
        Vector3f height;
    public:
    /**
     * @brief Construct a new Quad object
     * 
     * @param origin_ 
     * @param width_ 
     * @param height_ 
     * @param mat_ 
     */
        Quad(Vector3f origin_, Vector3f width_, Vector3f height_,Material mat_);

        /**
         * @brief Renvoi un booléen en fonction de s'il y a intersection entre le rayon et le plan ou non. Modifie également par référence
         *  P,N, et t qui permettent ensuite de calculer l'intensité de la lumière au point courant.
         * 
         * @param r 
         * @param P 
         * @param N 
         * @param t 
         * @return true 
         * @return false 
         */
        bool is_hit(const Ray3f &r,Vector3f & P, Vector3f & N,float &t) const;
};

#endif