#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <vector>
#include <opencv2/opencv.hpp>
#include "World.hpp"

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

	double GetX() const {return x;}
	double GetY() const {return y;}
	double GetH() const {return h;}
	double GetW() const {return w;}

	static void CreateRandom(std::vector<Particle>& particles, const int count, const World& world);
	static void DrawParticles(cv::Mat& img, const std::vector<Particle>& particles);
};
#endif