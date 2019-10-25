#include "ParticleForceGenerator.h"

ParticleForceGenerator::ParticleForceGenerator(PxTransform* tr, Vector3 pos, double tam, double force) {
	tr_ = tr;
	pos_ = pos;
	force_ = force;
	forcedir_ = Vector3(force_/500, 0.0, 0.0);
	tam_ = tam;
	field_ = new Particle(CreateShape(PxSphereGeometry(tam_)), tr_, pos_, 0);
	field_->setVelocity(Vector3(0.0, 0.0, 0.0));
	field_->setAcceleration(Vector3(0.0, 0.0, 0.0));
}

ParticleForceGenerator::~ParticleForceGenerator() {
	delete field_;
}

bool ParticleForceGenerator::detectParticle(Particle* particle) {
	return (particle->getPosition() - pos_).normalize() < tam_;
}


