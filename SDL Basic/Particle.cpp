#include "Particle.h"
#include <stdlib.h>


Particle::Particle()
{
	m_x = ((2.0 * rand()) / RAND_MAX) - 1;
	m_y = ((2.0 * rand()) / RAND_MAX) - 1;
}


Particle::~Particle()
{
}

void Particle::update()
{
	
	const double x_speed = SPEEDCONSTANT * (((2.0 * rand()) / RAND_MAX) - 1);
	const double y_speed = SPEEDCONSTANT * (((2.0 * rand()) / RAND_MAX) - 1);
	
	m_x += x_speed;
	m_y += y_speed;
}