#pragma once
#include "ParticleForceGenerator.h"
class ParticleGravity :
	public ParticleForceGenerator
{
public:
	ParticleGravity(PxTransform* tr, Vector3 pos, double tam, double force) : ParticleForceGenerator(tr, pos, tam, force) {}

	virtual void updateForce(Particle* particle, float t);
};

