#pragma once

#include "ParticleForceGenerator.h"

class ParticleForceRegistry
{
protected:
	struct ParticleForceRegistration {
		Particle* particle;
		ParticleForceGenerator* fg;

		bool operator==(ParticleForceRegistration a) {
			if (particle == a.particle && fg == a.fg) return true;
			else return false;
		}
	};

	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;

public:

	void add(Particle* particle, ParticleForceGenerator* fg);
	void remove(Particle* particle, ParticleForceGenerator* fg);
	void clear();
	void updateForces(float t);

};

