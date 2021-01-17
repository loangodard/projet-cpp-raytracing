#ifndef VECTOR3F_H
#define VECTOR3F_H
#include <iostream>
#include <math.h>

/**
 * @brief Vecteurs de dimensions 3
 * 
 */
class Vector3f {
	private:
	/**
	 * @brief Contient les valeurs de chaque composante d
	 * 
	 */
		float x,y,z;
	public:
		/**
		 * @brief Construct a new Vector 3f object
		 * 
		 * @param x_ 
		 * @param y_ 
		 * @param z_ 
		 */
		Vector3f(float x_ = 0, float y_ = 0, float z_ = 0);

		/**
		 * @brief Construct a new Vector 3f object, constructeur de copie
		 * 
		 * @param v 
		 */
		Vector3f(const Vector3f & v);

		/**
		 * @brief Get the x object
		 * 
		 * @return float 
		 */
		float get_x() const;

		/**
		 * @brief Get the y object
		 * 
		 * @return float 
		 */
		float get_y() const;

		/**
		 * @brief Get the z object
		 * 
		 * @return float 
		 */
		float get_z() const;

		/**
		 * @brief Affiche le vecteur sur la sortie standard au format (x;y;z)
		 * 
		 */
		void print_vector() const;
};

/**
 * @brief Surchage de l'operateur *, c'est en fait le produit scalaire entre deux vecteurs
 * 
 * @param v1 
 * @param v2 
 * @return float 
 */
float operator*(const Vector3f & v1, const Vector3f & v2);

/**
 * @brief Surchage de l'operateur * entre un scalaire et un vecteur
 * 
 * @param a 
 * @param v2 
 * @return Vector3f 
 */
Vector3f operator*(float a, const Vector3f & v2);

/**
 * @brief Surchage de l'operateur / entre un vecteur et un scalaire
 * 
 * @param v2 
 * @param a 
 * @return Vector3f 
 */
Vector3f operator/(const Vector3f & v2,float a);

/**
 * @brief Surcharge de l'operateur + entre deux vecteurs
 * 
 * @param v1 
 * @param v2 
 * @return Vector3f 
 */
Vector3f operator+(const Vector3f & v1, const Vector3f & v2);

/**
 * @brief Surcharge de l'operateur - entre deux vecteurs
 * 
 * @param v1 
 * @param v2 
 * @return Vector3f 
 */
Vector3f operator-(const Vector3f & v1, const Vector3f & v2);

/**
 * @brief Renvoi la norme du vecteur entré
 * 
 * @param v1 
 * @return float 
 */
float norme(const Vector3f & v1);

/**
 * @brief Produit vectoriel entre deux vecteurs
 * 
 * @param u 
 * @param v 
 * @return Vector3f 
 */
Vector3f vectoriel(const Vector3f & u, const Vector3f & v);

/**
 * @brief Renvoie le vecteur normalisé du vecteur entré
 * 
 * @param v 
 * @return Vector3f 
 */
Vector3f get_normalized(const Vector3f & v);

#endif