#pragma once
#include"vector3.h"
namespace phy{
class Matrix16{
	public:
		real m[4][4];
	public:
		Matrix16 operator +(const Matrix16& m1);
		Matrix16 operator -(const Matrix16& m1);
		Matrix16 operator *(const Matrix16& m1);
		void operator +=(const Matrix16& m1);
		void operator -=(const Matrix16& m1);
		void operator *=(const Matrix16& m1);
		bool operator ==(const Matrix16& m1);
		bool operator !=(const Matrix16& m1);

		
	
};
}
