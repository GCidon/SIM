#pragma once
#include "Particle.h"

class Firework :
	public Particle
{
public:
	Firework(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos, Vector3 velo, int type);
	~Firework();

	void explode();
	void update(float t);
	int lifeFirst, lifeSecond;
	int type_;

protected:

	vector<Particle*> particulas;

	bool active = true;
	int cant;
	PxShape* pShape;
};
