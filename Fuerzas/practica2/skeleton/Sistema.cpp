#include "Sistema.h"
#include <iostream>

Sistema::Sistema(PxTransform* tr, Vector3 pos, PxShape* sh, double g) {
	transform_ = tr;
	pos_ = pos;
	pShape = sh;
	period = 0;
	g_ = g;
}

void Sistema::update(float t) {
	period += t;

	if (period > 0.01) {
		Vector3 ini = pos_;
		PxTransform* transform = new PxTransform(ini);
		Particle* p = new Particle(pShape, transform, ini, 2);
		p->setVelocity(Vector3(rand()%100 -50, 50.0, rand() % 100 - 50));
		p->setAcceleration(Vector3(0.0, -g_, 0.0));
		particulas.push_back(p);
		period = 0;
	}

	for each (auto shot in particulas) {
		shot->integrate(t);
		if (shot->getLifespan() >= 3) {
			delete shot;
			shot = nullptr;
		}
	}
}
