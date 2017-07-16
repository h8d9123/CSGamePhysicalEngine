#include<stdio.h>
#include<iostream>
using namespace std;
#include"vector3.h"
int main(){
	phy::Vector3 v(1,2,4);
	v+=(v);
	v=v+v;
	cout<<v.x<<","<<v.y<<","<<v.z<<endl;
	return 0;
}
