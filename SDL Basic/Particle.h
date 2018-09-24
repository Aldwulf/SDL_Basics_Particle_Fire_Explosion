#pragma once

/// member variable in a struct are public by default
struct Particle
{

	double m_x;
	double m_y;

public:
	Particle();
	~Particle();
};

