#pragma once

/// member variable in a struct are public by default
struct Particle
{
	const double SPEEDCONSTANT = 0.01;
	double m_x;
	double m_y;
	double m_xspeed;
	double m_yspeed;

public:
	Particle();
	~Particle();

	void update();
};

