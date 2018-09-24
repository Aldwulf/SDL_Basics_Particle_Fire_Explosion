#pragma once

#include "Particle.h"

class Swarm
{
public:
	const static int NPARTICLES = 5000;

private:
	Particle *m_pParticles;
	int lastTime;

public:
	Swarm();
	~Swarm();

	void update(int elapsedTime);

	const Particle * const getParticles() { return m_pParticles; };
};

