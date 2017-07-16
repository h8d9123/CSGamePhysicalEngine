/*
 * holds a vector 3 dimensions
 */
#pragma once
#include<stdio.h>
#include<math.h>
namespace phy{

#define real_sqrtf sqrtf
typedef float real;
class Vector3{
	public:
		real x,y,z;
	private:
		real pad;
	public:
		Vector3(real x, real y, real z):x(x),y(y),z(z){};
		Vector3(real c):x(c), y(c), z(c){};
		Vector3(const Vector3& v):x(v.x), y(v.y), z(v.z){};

		Vector3 operator+(const Vector3 &v);
		Vector3 operator-(const Vector3 &v);
		Vector3 operator*(const Vector3 &v);
		Vector3 operator/(const Vector3 &v);

		Vector3 & operator +=(const Vector3 &v);
		Vector3 & operator -=(const Vector3 &v);
		Vector3 & operator *=(const Vector3 &v);
		Vector3 & operator /=(const Vector3 &v);
		real magnitude() const{
		return real_sqrtf(x*x + y*y + z*z);
		};
		real squareMagnitude() const{
			return (x*x + y*y + z*z);
		};
		void normalize(){
			real l = magnitude();
			if(l>0){
				x/=l;
				y/=l;
				z/=l;
			}
		}
};
}
