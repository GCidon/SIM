#include "Firework.h"

bool Firework::update(float t) {
	integrate(t);
	age -= t;
	return (age < 0);
}

void Firework::initFireworkRules() {
	rules[0]->setParameters(1, 0.5f, 1.4f, Vector3(-5, 25, -5), Vector3(5, 28, 5), 0.1);
	rules[0]->payloads.push_back(Payload(1, 5));

	rules[1]->setParameters(1, 0.5f, 1.4f, Vector3(-10, 10, -10), Vector3(20, 50, 20), 0.1);
	rules[1]->payloads.push_back(Payload(2, 5));

	rules[2]->setParameters(1, 0.5f, 1.4f, Vector3(-1, 30, -1), Vector3(2, 75, 2), 0.1);
	rules[2]->payloads.push_back(Payload(3, 5));
}

bool Firework::isActive() const {
	return type != 0;
}

void Firework::setInactive() {
	type = 0;
}

Firework::FireworkRule* Firework::getRuleFromType(unsigned type) {
	return rules[type];
}

void Firework::integrate(float t) {
	Particle::integrate(t);
	while (true) break;
}

