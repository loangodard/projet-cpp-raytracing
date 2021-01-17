#ifndef MATERIAL_H
#define MATERIAL_H


/**
 * @brief Matériaux
 */
class Material{
    private:
    /**
     * @brief Couleur de la forme au format RGB et brillance de la forme
     * 
     */
        float r,g,b;
        float shininess;
    public:
    /**
     * @brief Construct a new Material object (constructeur de copie)
     * 
     * @param m 
     */
        Material(Material const & m);

        /**
         * @brief Construct a new Material object
         * 
         * @param r 
         * @param g 
         * @param b 
         * @param shininess 
         */
        Material(float r, float g, float b, float shininess);

        /**
         * @brief Get the r object
         * 
         * @return float 
         */
        float get_r() const;

        /**
         * @brief Get the g object
         * 
         * @return float 
         */
        float get_g() const;

        /**
         * @brief Get the b object
         * 
         * @return float 
         */
        float get_b() const;

        /**
         * @brief Get the shininess object
         * 
         * @return float 
         */
        float get_shininess() const; 
};

#endif