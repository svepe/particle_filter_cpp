#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
private:
	double x;
	double y;
	double h;
	double w;

public:
	Particle(double x_, double y_, double h_, double w_ = 1, bool noisy = false);
	~Particle();
	
};
#endif