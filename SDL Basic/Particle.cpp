#define _USE_MATH_DEFINES

#include "Particle.h"
#include <stdlib.h>
//#include <cmath>
#include <math.h>

using namespace std;

Particle::Particle() : m_x(0), m_y(0)
{
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (SPEEDCONSTANT * rand()) / RAND_MAX;
}


Particle::~Particle()
{
}

void Particle::update()
{
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed;
	m_y += yspeed;
}