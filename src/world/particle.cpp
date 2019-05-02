#include"particle.h"
using namespace phy;
void Particle::Update(real worldTime){
	real dt = worldTime - t;
	pos += v*dt + a*dt*dt*0.5;
	v += a*dt;
	t = worldTime;
}
void Particle::SetMass(real mass){
	invmass = 1.0/mass;
}
real Particle::GetMass(){
	return 1.0/invmass;
}
void Particle::SetVolectity(real vx, real vy, real vz){
	this->v.x = vx;
	this->v.y = vy;
	this->v.z = vz;
}
void Particle::SetVolectity(Vector3 v){
	this->v = v;
}
Vector3 Particle::GetVolectity(){
	return v;
}
void Particle::SetAccelarate(real ax, real ay, real az){
	a.x = ax;
	a.y = ay;
	a.z = az;
}
void Particle::SetAccelarate(Vector3 a){
	this->a = a;
}
Vector3 Particle::GetAccelarate(){
	return a;
}


