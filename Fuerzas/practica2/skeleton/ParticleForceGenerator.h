#pragma once

#include "Particle.h"

class ParticleForceGenerator
{
protected:
	PxTransform* tr_;
	Vector3 pos_;
	Vector3 forcedir_;
	Particle* field_;

	double force_;
	double tam_;

public:
	ParticleForceGenerator(PxTransform* tr, Vector3 pos, double tam, double force);
	~ParticleForceGenerator();

	void detectParticle(Particle* particle);
	virtual void updateForce(Particle* particle, float t) = 0;

};

