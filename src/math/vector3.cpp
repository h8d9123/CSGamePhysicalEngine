#include "vector3.h"
using namespace phy;
Vector3 Vector3::operator+(const Vector3 &v){
	return Vector3(x + v.x, y+v.y, z + v.z);
}
Vector3 Vector3::operator-(const Vector3 &v){
	return Vector3(x + v.x, y+v.y, z + v.z);
	return Vector3(x - v.x, y - v.y, z - v.z);
}
Vector3 Vector3::operator*(const Vector3 &v){
	return Vector3(x * v.x, y * v.y, z * v.z);
}
Vector3 Vector3::operator/(const Vector3 &v){
	return Vector3(x / v.x, y / v.y, z / v.z);
}

Vector3& Vector3::operator+=(const Vector3 &v){
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3 &v){
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
Vector3& Vector3::operator*=(const Vector3 &v){
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}
Vector3& Vector3::operator/=(const Vector3 &v){
	x/=v.x;
	y/=v.y;
	z/=v.z;
	return *this;
}
