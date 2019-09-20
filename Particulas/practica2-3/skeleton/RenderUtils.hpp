#ifndef __RENDER_UTILS_H__
#define __RENDER_UTILS_H__

#include "PxPhysicsAPI.h"
#include "core.hpp"

using namespace physx;

class RenderItem;
void RegisterRenderItem(const RenderItem* _item);
void DeregisterRenderItem(const RenderItem* _item);

class RenderItem
{
public:
	RenderItem(physx::PxShape* _shape, const physx::PxTransform* _trans, const Vector4& _color) :
		shape(_shape), transform(_trans), actor(NULL), color(_color), references(1)
	{
		shape->acquireReference();
		RegisterRenderItem(this);
	}

	RenderItem(physx::PxShape* _shape, const Vector4& _color) :
		shape(_shape), transform(NULL), actor(NULL), color(_color), references(1)
	{
		shape->acquireReference();
		RegisterRenderItem(this);
	}

	RenderItem(physx::PxShape* _shape, const physx::PxRigidActor* _actor, const Vector4& _color) :
		shape(_shape), transform(NULL), actor(_actor), color(_color), references(1)
	{
		shape->acquireReference();
		RegisterRenderItem(this);
	}

	RenderItem() : shape(NULL), transform(NULL), references(1) {}

	void addReference()
	{
		++references;
	}

	void release()
	{
		--references;
		if (references == 0)
		{
			DeregisterRenderItem(this);
			shape->release();
			delete this;
		}
	}

public:
	physx::PxShape* shape;
	const physx::PxTransform* transform;
	const physx::PxRigidActor* actor;
	Vector4 color;

	unsigned references;
};

class Particle {

protected:
	RenderItem* item;
	PxTransform* transform;
	Vector3 p;
	Vector3 v;
	Vector3 a;
	float speed;
	float damping;
	float inverse_mass;

public:

	Particle(physx::PxShape* sh, physx::PxTransform* transf, Vector3 pos, Vector3 vel, Vector3 acel, float mass)
	{
		p = pos;
		v = vel;
		a = acel;
		transform = transf;
		item = new RenderItem(sh, transf, Vector4(255, 255, 0, 0));
		inverse_mass = 1 / mass;
		damping = 0.99;
	}

	void integrate(float t) {
		if (inverse_mass <= 0.0f) return;
		p += v * t;
		v += a * t;
		v *= powf(damping, t);
		*transform = PxTransform(p);
	}
};

double GetLastTime();
Camera* GetCamera();

physx::PxShape* CreateShape(const physx::PxGeometry& geo);

#endif