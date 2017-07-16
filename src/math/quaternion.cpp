#include"quaternion.h"
using namespace phy;
void Quaternion::operator +=(const Quaternion& q){
	for(int m=0;m<4;m++){
		data[m]+=q.data[m];
	}
}

void Quaternion::operator -=(const Quaternion& q){
	for(int m=0;m<4;m++){
		data[m]-=q.data[m];
	}
}
void Quaternion::operator *=(const Quaternion& q){
	Quaternion q1 = *this;
	r= q1.r*q.r - q1.i*q.i - q1.j*q.j - q1.k*q.k;
	i= q1.r*q.i + q1.i*q.r - q1.j*q.k - q1.k*q.j;
	j= q1.r*q.j + q1.j*q.r - q1.k*q.i - q1.i*q.k;
	k= q1.r*q.k + q1.k*q.r + q1.i*q.j - q1.j*q.i;

}
