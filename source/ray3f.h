#include "vector3f.h"
#ifndef RAY3F_H
#define RAY3F_H

/**
 * @brief Rayons
 * 
 */
class Ray3f{
    private:
    /**
     * @brief Origine et direction du rayon
     * 
     */
        Vector3f origin;
        Vector3f direction;
    public:
    /**
     * @brief Construct a new Ray 3f object
     * 
     * @param origin_ 
     * @param direction_ 
     */
        Ray3f(Vector3f origin_, Vector3f direction_);

        /**
         * @brief Get the origin object
         * 
         * @return Vector3f 
         */
        Vector3f get_origin() const;

        /**
         * @brief Get the direction object
         * 
         * @return Vector3f 
         */
        Vector3f get_direction() const;
};

#endif