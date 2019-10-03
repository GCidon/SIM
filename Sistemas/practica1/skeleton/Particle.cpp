#include "Particle.h"

Particle::Particle(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos, int type)
{
	p = pos;
	transform = transf;
	item = new RenderItem(sh, transf, Vector4(255, 255, 0, 0));
	speed = 100;
	switch (type) {
	case 0:
		setMass(2.0f); // 2.0 Kg
		setVelocity(Vector3(0.0f, 0.0f, 35.0f)); // 35 m/s
		setAcceleration(Vector3(0.0f, -1.0f, 0.0f));
		setDamping(0.99f);
		break;
	case 1:
		setMass(200.0f); // 200.0 Kg
		setVelocity(Vector3(0.0f, 30.0f, 40.0f));
		setAcceleration(Vector3(0.0f, -20.0f, 0.0f));
		setDamping(0.99f);
		break;
	case 2:
		setMass(1.0f); // 1.0 Kg
		setVelocity(Vector3(0.0f, 0.0f, 10.0f));
		setAcceleration(Vector3(0.0f, 0.6f, 0.0f)); // floats
		setDamping(0.9f);
		break;
	case 3:
		setMass(0.1f); // almost no weight
		setVelocity(Vector3(0.0f, 0.0f, 100.0f)); // No gravity
		setAcceleration(Vector3(0.0f, 0.0f, 0.0f));
		setDamping(0.99f);
		break;
	}
}

Particle::~Particle() {
	delete transform;
	item->release();
}

void Particle::integrate(float t) {
	if (inverse_mass <= 0.0f) return;
	p += v * speed * t;
	v += a * t;
	v *= powf(damping, t);
	*transform = PxTransform(p);
	lifespan += t;
}

float Particle::getMass() {
	return 1 / inverse_mass;
}

Vector3 Particle::getPosition() {
	return p;
}

Vector3 Particle::getVelocity() {
	return v;
}

Vector3 Particle::getAcceleration() {
	return a;
}

float Particle::getDamping() {
	return damping;
}

float Particle::getLifespan() {
	return lifespan;
}


void Particle::setPosition(Vector3 velo) {
	p = velo;
}

void Particle::setMass(float m) {
	inverse_mass = 1 / m;
}

void Particle::setVelocity(Vector3 velo) {
	v = velo;
}

void Particle::setAcceleration(Vector3 velo) {
	a = velo;
}

void Particle::setDamping(float m) {
	damping = m;
}

