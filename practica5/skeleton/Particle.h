#pragma once

#include "RenderUtils.hpp"

using namespace physx;
using namespace std;

class Particle {

protected:

	RenderItem* item;
	PxTransform* transform;
	Vector3 p;
	Vector3 v;
	Vector3 a;
	float speed;
	float damping;
	float inverse_mass;
	float lifespan = 0;

public:

	Particle(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos, int type);
	~Particle();

	void integrate(float t);

	float getMass() const;
	Vector3 getPosition() const;
	Vector3 getVelocity() const;
	Vector3 getAcceleration() const;
	float getDamping() const;
	float getLifespan() const;

	void setMass(float m);
	void setPosition(Vector3 velo);
	void setVelocity(Vector3 velo);
	void setAcceleration(Vector3 velo);
	void setDamping(float m);
};
