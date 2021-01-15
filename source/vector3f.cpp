#include "vector3f.h"

Vector3f::Vector3f(float x_, float y_, float z_){
	x=x_;
	y=y_;
	z=z_;
}

Vector3f::Vector3f(const Vector3f & v){
	x=v.get_x();
	y=v.get_y();
	z=v.get_z();
}

float Vector3f::get_x() const{
	return x;
}

float Vector3f::get_y() const{
	return y;
}

float Vector3f::get_z()const {
	return z;
}

void Vector3f::print_vector() const {
	std::cout << '(' << x << ';' << y << ';' << z <<')'<<std::endl;
}

float operator*(const Vector3f & v1, const Vector3f & v2){
	float x_r = v1.get_x()*v2.get_x();
	float y_r = v1.get_y()*v2.get_y();
	float z_r = v1.get_z()*v2.get_z();
	return (x_r+y_r+z_r);
}

Vector3f operator*(float a, const Vector3f & v2){
	return (Vector3f(a*v2.get_x(),a*v2.get_y(),a*v2.get_z()));
}

Vector3f operator+(const Vector3f & v1, const Vector3f & v2){
	return Vector3f(v1.get_x()+v2.get_x(),v1.get_y()+v2.get_y(),v1.get_z()+v2.get_z());
}

Vector3f operator-(const Vector3f & v1, const Vector3f & v2){
	Vector3f a = v1;
	Vector3f b = (-1)*v2;
	return(a+b);
}

Vector3f operator/(const Vector3f & v2,float a){
	if(a == 0) throw("Error, 0 division");
	return(v2*(1/a));
}

float norme(const Vector3f & v1){
	return(sqrt(v1*v1));
}

Vector3f vectoriel(const Vector3f & u, const Vector3f & v){
	return Vector3f(
		u.get_y()*v.get_z()-u.get_z()*v.get_y(),
		u.get_z()*v.get_x()-u.get_x()*v.get_z(),
		u.get_x()*v.get_y()-u.get_y()*v.get_x()
		);
}

Vector3f get_normalized(const Vector3f & v){
	float n = sqrt(v*v);
	Vector3f r = Vector3f(v.get_x()/n,v.get_y()/n,v.get_z()/n);
	return r;
}

// int main(){
// 	Vector3f width = Vector3f(2,2,0);
//     Vector3f height = Vector3f(3,2,0);
// 	Vector3f normal = vectoriel(width,height);
// 	Vector3f normalized = get_normalized(normal);
// 	normalized.print_vector();
// 	std::cout << norme(normalized) << std::endl;
// 	return 0;
// }