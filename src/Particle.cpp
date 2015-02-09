#include "Particle.hpp"	
#include "Utils.hpp"

Particle::Particle(double x_, double y_, double h_, double w_, bool noisy)
{
	x = x_;
	y = y_;
	w = w_;

	if(noisy)
	{
		x = add_noise(0.1, x);
		y = add_noise(0.1, y);
		h = add_noise(0.1, h);
	}
}