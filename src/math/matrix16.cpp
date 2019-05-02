#include"matrix16.h"
#include<cstring>
using namespace phy;
Matrix16 Matrix16::operator +(const Matrix16& m1){
	Matrix16 tmp;
	for(unsigned int i=0; i<4;i++){
		for(unsigned int j=0;j<4; j++){
			tmp.m[i][j] = this->m[i][j] + m1.m[i][j];
		}
	}
	return tmp;
}
Matrix16 Matrix16::operator -(const Matrix16& m1){
	Matrix16 tmp;
	for(unsigned int i=0; i<4;i++){
		for(unsigned int j=0;j<4;j++){
			tmp.m[i][j] = this->m[i][j] - m1.m[i][j];
		}
	}
	return tmp;
}

void Matrix16::operator +=(const Matrix16& m1){
	for(unsigned int i=0; i<4;i++){
		for(unsigned int j=0;j<4;j++){
		this->m[i][j] += m1.m[i][j];
		}
	}
}
void Matrix16::operator -=(const Matrix16& m1){
	for(unsigned int i=0; i<4;i++){
		for(unsigned int j=0;j<4; j++){
		this->m[i][j] -= m1.m[i][j];
		}
	}
}
Matrix16 Matrix16::operator *(const Matrix16& m1){
	Matrix16 tmp;
	for(unsigned int i=0; i<4;i++){
		for(unsigned int j=0;j<4;j++){
			for(unsigned int k=0;k<4;k++){
				tmp.m[i][j]+=this->m[i][k] + m1.m[k][j];
			}

		}
	}
	return tmp;
}
void Matrix16::operator *=(const Matrix16& m1){
	Matrix16 tmp;
	for(unsigned int i=0; i<4;i++){
		for(unsigned int j=0;j<4;j++){
			for(unsigned int k=0;k<4;k++){
				tmp.m[i][j]+=this->m[i][k] + m1.m[k][j];
			}
		}
	}	
	memcpy(&m, &m1, sizeof(m));
}
bool Matrix16::operator ==(const Matrix16& m1){
	for(int i=0;i<4;i++){
		for(int j=0; j<4;j++){
			if (m[i][j]!=m1.m[i][j]) return false;
		}
	}
	return true;
}
bool Matrix16::operator !=(const Matrix16& m1){
	return !(*this==m1);
}
