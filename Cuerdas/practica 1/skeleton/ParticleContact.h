#pragma once
#include "Particle.h"

class ParticleContact
{
public:
	Particle* particle[2];
	float restitution;
	Vector3 contactNormal;
	float penetration;

protected:
	void resolve(float t);
	float calculateSeparatingVelocity() const;
	void resolveInterpenetration(float t);

private:
	void resolveVelocity(float t);
};

