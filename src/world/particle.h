#pragma once
#include"../math/vector3.h"

namespace phy{
	class Particle{
		public:
			Vector3 pos;
			Vector3 v;
			Vector3 a;
			real invmass;
			real t;

		public:
			Particle(real x,real y, real z,real invmass):pos(x,y,z),invmass(invmass){};
			Particle():pos(0),invmass(0){};
			void MoveTo(real x,real y, real z){pos.x = x; pos.y =y; pos.z = z;};
			void MoveTo(Vector3 pos){this->pos = pos;};
			void Update(real worldtTime);
			void SetMass(real mass);
			real GetMass();
			void SetVolectity(real vx,real vy, real vz);
			void SetVolectity(Vector3 v);
			Vector3 GetVolectity();
			void SetAccelarate(Vector3 a);
			void SetAccelarate(real ax, real ay, real az);
			Vector3 GetAccelarate();
	};
}
