#pragma once

#include "Particle.h"

class Sistema
{
public:
	Sistema(PxTransform* tr, Vector3 pos, PxShape* sh, double g);
	vector<Particle*> particulas;

	virtual void update(float t);

protected:

	PxTransform* transform_;
	Vector3 pos_;
	PxShape* pShape;

	double g_;
	float period;
	
};

