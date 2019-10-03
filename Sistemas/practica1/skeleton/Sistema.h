#pragma once

#include "Particle.h"

class Sistema
{
public:
	Sistema(PxTransform* tr, Vector3 pos, PxShape* sh);
	vector<Particle*> particulas;

	void update(float t);

protected:

	PxTransform* transform_;
	Vector3 pos_;
	PxShape* pShape;

	float period;
	
};

