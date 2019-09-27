#pragma once
#include "Particle.h"
class Firework : public Particle
{
	struct Payload {
		unsigned type;
		unsigned count;
		Payload(unsigned _type, unsigned _count) {
			type = _type;
			count = _count;
		}
	};

	struct FireworkRule {

		unsigned type;
		float minAge;
		float maxAge;

		Vector3 minVelocity;
		Vector3 maxVelocity;
		float damping;

		vector<Payload> payloads;

		void setParameters(unsigned t, float min, float max, Vector3 minV, Vector3 maxV, float d) {
			type = t;
			minAge = min;	maxAge = max;
			minVelocity = minV;	maxVelocity = maxV;
			damping = d;
		}

		void create(Firework* firework, const Firework* parent = NULL) const {
			firework->type = type;
			firework->age = random(minAge, maxAge);
			Vector3 vel;
			if (parent)
			{ // inherit velocity from parent
				firework->setPosition(parent->getPosition());
				vel = parent->getVelocity();
			}
			else
			{
				Vector3 start;
				int x = random(1, 3) - 1;
				start.x = 5.0f * x;
				firework->setPosition(start);
			}
			vel += random(minVelocity, maxVelocity);
			firework->setVelocity(vel);
			// Force the mass to 1
			firework->setMass(1);
			firework->setDamping(damping);
			firework->setAcceleration(Vector3(0.0, -9.8, 0.0));
			//firework->clearAccumulator();
		}

	};

public:
	unsigned type;
	float age;
	FireworkRule* rules[3];

	bool update(float t);
	void initFireworkRules();
	bool isActive() const;
	void setInactive();

	virtual void integrate(float t);

	FireworkRule* getRuleFromType(unsigned type);
};

