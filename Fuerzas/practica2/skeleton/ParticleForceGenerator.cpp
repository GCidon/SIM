#include "ParticleForceGenerator.h"

ParticleForceGenerator::ParticleForceGenerator(PxTransform* tr, Vector3 pos, double tam, double force) {
	tr_ = tr;
	pos_ = pos;
	force_ = force;
	forcedir_ = Vector3(0.0, force_, 0.0);
	tam_ = tam;
	field_ = new Particle(CreateShape(PxSphereGeometry(tam_)), tr_, pos_, 0);
	field_->setVelocity(Vector3(0.0, 0.0, 0.0));
	field_->setAcceleration(Vector3(0.0, 0.0, 0.0));
}

ParticleForceGenerator::~ParticleForceGenerator() {
	delete field_;
}

void ParticleForceGenerator::detectParticle(Particle* particle) {
	if (particle->getPosition().x < pos_.x + tam_ && particle->getPosition().x > pos_.x - tam_ &&
		particle->getPosition().y < pos_.y + tam_ && particle->getPosition().y > pos_.y - tam_ &&
		particle->getPosition().z < pos_.z + tam_ && particle->getPosition().z > pos_.z - tam_)
		particle->setVelocity(forcedir_);
}


