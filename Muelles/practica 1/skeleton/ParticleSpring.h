#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
	public ParticleForceGenerator
{
private:
	Particle* other_;
	float k_;
	float restLength_;

public:
	ParticleSpring(PxTransform* tr, Particle* o, float k, float restLength) : ParticleForceGenerator(tr, Vector3(0.0, 50.0, 0.0), 2, 0.0) {
		other_ = o;
		k_ = k;
		restLength_ = restLength;
	}

	virtual void updateForce(Particle* particle, float t);

	void addK(float aux) { k_ += aux; }
};

