#include "ParticleForceRegistry.h"

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* fg) {
	ParticleForceRegistration nuevo;
	nuevo.particle = particle;
	nuevo.fg = fg;
	//vector<ParticleForceRegistration>::iterator it = std::find(registrations.begin(), registrations.end(), nuevo);
	//if(it == registrations.end())
		registrations.push_back(nuevo);
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* fg) {
	int i = 0;
	while (i < registrations.size() && (registrations.at(i).particle != particle || registrations.at(i).fg != fg)) { 
		i++; 
	}
	if (i < registrations.size()) {
		registrations.erase(registrations.begin() + i);
	}
}

void ParticleForceRegistry::clear() {
	registrations.clear();
}

void ParticleForceRegistry::updateForces(float t) {
	for (auto it = registrations.begin(); it != registrations.end(); ++it) {
		it->fg->updateForce(it->particle, t);
	}
}
