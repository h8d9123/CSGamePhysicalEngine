#pragma once
#include "vector3.h"
namespace phy{
	class Quaternion{
	public:
		union{
			struct{
				real r, i, j, k;
			};
			real data[4];
		};
	public:
		void normalize(){
			real d= r*r + i*i + j*j + k*k;
			if(d==0){
				r=1;
				return;
			}
			d = ((real)1.0)/real_sqrtf(d);
			r *= d;
			i *= d;
			j *= d;
			k *= d;
		}
	Quaternion(real r, real i, real j, real k):r(r),i(i), j(j),k(k){};
	Quaternion(real data[4]):r(data[0]), i(data[1]), j(data[2]), k(data[3]){};
	Quaternion(const Quaternion &q) {r =q.r; i = q.i, j = q.j; k = q.k;};
	Quaternion  operator +(const Quaternion&);
	Quaternion  operator -(const Quaternion&);
	Quaternion  operator *(const Quaternion&);
	Quaternion  operator /(const Quaternion&);

	void operator +=(const Quaternion&);
	void operator -=(const Quaternion&);
	void operator *=(const Quaternion&);
	void operator /=(const Quaternion&);


	};
}
