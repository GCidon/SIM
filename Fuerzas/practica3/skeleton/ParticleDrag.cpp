#include "ParticleDrag.h"

void ParticleDrag::updateForce(Particle* particle, float t) {
	Vector3 f;
	f = particle->getVelocity();

	float dragCoeff = f.normalize();
	dragCoeff = k1_ * dragCoeff + k2_ * dragCoeff * dragCoeff;

	f *= -dragCoeff;
	particle->addForce(f);
}
