#include "Particle.hpp"	
#include "Utils.hpp"

#include <cmath>

Particle::Particle(double x_, double y_, double h_, double w_, bool noisy)
{
	x = x_;
	y = y_;
	h = h_;
	w = w_;

	if(noisy)
	{
		x = Utils::add_noise(0.1, x);
		y = Utils::add_noise(0.1, y);
		h = Utils::add_noise(0.1, h);
	}
}

Particle::~Particle()
{

}

void Particle::CreateRandom(std::vector<Particle>& particles, const int count, const World& world)
{
	particles.clear();
	for(int i =0; i < count; ++i)
	{
		double x = Utils::sample_uniform(0, world.GetWidth());
		double y = Utils::sample_uniform(0, world.GetHeight());
		double h = Utils::sample_uniform(0, 2*M_PI);
		particles.push_back(Particle(x, y, h));
	}
}

void Particle::DrawParticles(cv::Mat& img, const std::vector<Particle>& particles)
{
	for(size_t i = 0; i < particles.size(); ++i)
	{
		cv::Point pt1 = cv::Point(particles[i].x, particles[i].y);
		cv::circle(img, pt1, 3, CV_RGB(255, 0, 255), CV_FILLED);

		const int r = 8;
		cv::Point pt2 = pt1 + cv::Point(cos(particles[i].h) * r, sin(particles[i].h) * r);
		cv::line(img, pt1, pt2, CV_RGB(255, 0, 255), 1);
	}
}