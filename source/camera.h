#include "vector3f.h"
#ifndef CAMERA_H
#define CAMERA_H

/**
 * @brief Caméras
 * 
 */
class Camera{
    private:
    /**
     * @brief Position et direction de la caméra
     * 
     */
        Vector3f position;
        Vector3f direction;
    public:
    /**
     * @brief Construct a new Camera object
     * 
     * @param position_ 
     * @param direction_ 
     */
        Camera(Vector3f position_, Vector3f direction_);

        /**
         * @brief Get the position object
         * 
         * @return Vector3f 
         */
        Vector3f get_position() const;
        
        /**
         * @brief Get the direction object
         * 
         * @return Vector3f 
         */
        Vector3f get_direction() const;
};

#endif