#pragma once

#include "ParticleForceGenerator.h"

class ParticleForceRegistry
{
protected:
	struct ParticleForceRegistration {
		Particle* particle;
		ParticleForceGenerator* fg;
	};

	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;

public:

	void add(Particle* particle, ParticleForceGenerator* fg);
	void remove(Particle* particle, ParticleForceGenerator* fg);
	void clear();
	void updateForces(float t);

};

