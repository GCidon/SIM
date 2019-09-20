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

public:

	Particle(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos, int type);

	void integrate(float t);

	float getMass();
	Vector3 getPosition();
	Vector3 getVelocity();
	Vector3 getAcceleration();
	float getDamping();

	void setMass(float m);
	void setPosition(Vector3 velo);
	void setVelocity(Vector3 velo);
	void setAcceleration(Vector3 velo);
	void setDamping(float m);
};

struct Payload {
	unsigned type;
	unsigned count;
	void set(unsigned _type, unsigned _count) {
		type = _type;
		count = _count;
	}
};
struct FireworkRule {
	unsigned type;
	float minAge;
	float maxAge;

	Vector3 minVelocity;
	Vector3 maxVelocity;
	float damping;

	vector<Payload> payloads;

	void setParameters(unsigned t, float min, float max, Vector3 minV, Vector3 maxV, float d) {
		type = t;
		minAge = min;	maxAge = max;
		minVelocity = minV;	maxVelocity = maxV;
		damping = d;
	}

	void create(Firework* firework, const Firework* parent = NULL) const {
		firework->type = type;
		firework->age = random(minAge, maxAge);
		if (parent)
		{ // inherit velocity from parent
			firework->setPosition(parent->getPosition());
			vel += parent->getVelocity();
		}
		else
		{
			Vector3 start;
			int x = random(1, 3) - 1;
			start.x = 5.0f * x;
			firework->setPosition(start);
		}
		vel += random(minVelocity, maxVelocity);
		firework->setVelocity(vel);
		// Force the mass to 1
		firework->setMass(1);
		firework->setDamping(damping);
		firework->setAcceleration(Vector3(0.0,-9.8,0.0));
		firework->clearAccumulator();
	}
	}
};

class Firework : public Particle {

public:
	unsigned type;
	float age;
	bool update(float t) {
		integrate(t);
		age -= t;
		return (age < 0);
	}
};
