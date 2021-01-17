#ifndef SHAPE_H
#define SHAPE_H
#include "material.h"
#include "ray3f.h"

/**
 * @brief Implémentation des formes
 * 
 */
class Shape{
    private:
    /**
     * @brief Matériel de la forme
     * 
     */
        Material matter;  
    public:
    /**
     * @brief Construct a new Shape object
     * 
     * @param mat 
     */
        Shape(Material mat);
        /**
         * @brief Get the material object
         * 
         * @return Material 
         */
        Material get_material() const;

        /**
         * @brief renvoi le rayon réfléchi (À implémenter)
         * 
         * @param ray 
         * @return Ray3f 
         */
        Ray3f reflect(Ray3f ray) const;

        /**
         * @brief Renvoi un booléen en fonction de s'il y a intersection entre le rayon et la forme ou non. Modifie également par référence
         *  P,N, et t qui permettent ensuite de calculer l'intensité de la lumière au point courant.
         * 
         * @param ray 
         * @param P 
         * @param N 
         * @param t 
         * @return true 
         * @return false 
         */
        bool is_hit(Ray3f ray,Vector3f& P, Vector3f& N, float& t) const;
};

#endif