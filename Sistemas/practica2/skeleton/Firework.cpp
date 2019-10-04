#include "Firework.h"

Firework::Firework(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos, Vector3 velo) : Particle(sh, transf, pos, 3) {
	Particle::setVelocity(velo);
	cant = 5;
	pShape = sh;
}

Firework::~Firework() {
	for (int i = 0; i < cant; i++) {
		Vector3 ini = p;
		PxTransform* transform = new PxTransform(ini);
		Particle* p = new Particle(pShape, transform, ini, 2);
		p->setVelocity(v);
	}
	Particle::~Particle();
}