#pragma once
#include "ParticleGravity.h"
#include <math.h>
class ParticleExplosion :
	public ParticleGravity
{
protected:
	
public:
	ParticleExplosion(PxTransform* tr, Vector3 pos, double tam, double force) : ParticleGravity(tr, pos, tam, force) {
		forcedir_ = Vector3(0.0, 0.0, 0.0);
	}

	virtual void updateForce(Particle* particle, float t) {
		if (1 / particle->getMass() == 0) return;

		float auxx = (pos_.x - particle->getPosition().x) * (pos_.x - particle->getPosition().x);
		float auxy = (pos_.y - particle->getPosition().y) * (pos_.y - particle->getPosition().y);
		float auxz = (pos_.z - particle->getPosition().z) * (pos_.z - particle->getPosition().z);
		float aux = sqrt(auxx + auxy + auxz);

		forcedir_ = ((pos_ - particle->getPosition()) * -aux);
		particle->addForce(forcedir_ * particle->getMass());
	}
};

