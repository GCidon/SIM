#include "ParticleForceRegistry.h"

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* fg) {
	ParticleForceRegistration nuevo;
	nuevo.particle = particle;
	nuevo.fg = fg;
	registrations.push_back(nuevo);
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* fg) {

}

void ParticleForceRegistry::clear() {
	registrations.clear();
}

void ParticleForceRegistry::updateForces(float t) {
	for (auto it = registrations.begin(); it != registrations.end(); ++it) {
		it->fg->updateForce(it->particle, t);
	}
}
