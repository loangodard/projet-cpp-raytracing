#ifndef VECTOR3F_H
#define VECTOR3F_H
#include <iostream>
#include <math.h>

class Vector3f {
	private:
		float x,y,z;
	public:
		Vector3f(float x_, float y_, float z_);
		Vector3f(const Vector3f & v);
		float get_x() const;
		float get_y() const;
		float get_z() const;
		void print_vector() const;
};

float operator*(const Vector3f & v1, const Vector3f & v2);
Vector3f operator*(float a, const Vector3f & v2);
Vector3f operator+(const Vector3f & v1, const Vector3f & v2);
Vector3f operator-(const Vector3f & v1, const Vector3f & v2);
float norme(const Vector3f & v1);
Vector3f vectoriel(const Vector3f & u, const Vector3f & v);
Vector3f get_normalized(const Vector3f & v);

#endif