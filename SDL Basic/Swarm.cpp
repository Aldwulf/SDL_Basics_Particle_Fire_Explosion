#include "Swarm.h"



Swarm::Swarm() : lastTime(0)
{
	m_pParticles = new Particle[NPARTICLES];
}


Swarm::~Swarm()
{
	delete[] m_pParticles;
}

// Call Particle::update() on each particle
void Swarm::update(int elapsedTime)
{
	int interval = elapsedTime - lastTime;

	for (int i = 0; i < Swarm::NPARTICLES; i++)
	{
		m_pParticles[i].update(interval);
	}

	lastTime = elapsedTime;
}