#pragma once
#include "ParticleForceGenerator.h"
class ParticleDrag :
	public ParticleForceGenerator
{
protected:
	float k1_;
	float k2_;

public:
	ParticleDrag(PxTransform* tr, Vector3 pos, double tam, double force, float k1, float k2) : ParticleForceGenerator(tr, pos, tam, force) {
		k1_ = k1;
		k2_ = k2;
	}

	virtual void updateForce(Particle* particle, float t);
};

