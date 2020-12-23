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
	int x_r = v1.get_x()*v2.get_x();
	int y_r = v1.get_y()*v2.get_y();
	int z_r = v1.get_z()*v2.get_z();

	return (x_r+y_r+z_r);
}

Vector3f operator*(float a, const Vector3f & v2){
	return (Vector3f(a*v2.get_x(),a*v2.get_y(),a*v2.get_z()));
}

Vector3f operator+(const Vector3f & v1, const Vector3f & v2){
	return Vector3f(v1.get_x()+v2.get_x(),v1.get_y()+v2.get_y(),v1.get_z()+v2.get_z());
}

Vector3f operator-(const Vector3f & v1, const Vector3f & v2){
	return(v1+(-1)*v2);
}

float norme(const Vector3f & v1){
	return(sqrt(v1*v1));
}

// int main(){
// 	Vector3f X = Vector3f(1,1,1);
// 	Vector3f Y = Vector3f(2,2,2);
// 	Vector3f Z = X-Y;
// 	X.print_vector();
// 	Y.print_vector();
// 	Z.print_vector();
// 	std::cout <<"->"<<X*Y<<std::endl;
// 	std::cout <<"->"<<norme(X)<<std::endl;
// 	return 0;
// }