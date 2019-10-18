#include "ParticleGravity.h"

void ParticleGravity::updateForce(Particle* particle, float t) {
	if (particle->getMass()/1 != 0) return;
	particle->addForce(forcedir_ * particle->getMass());
}
