#pragma once
#include "Particle.h"
class Firework :
	public Particle
{
public:
	Firework(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos);
};

