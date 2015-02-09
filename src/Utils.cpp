#include "Utils.hpp"
#include <random>



double add_noise(double level, double x)
{
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(-level,level);

	double noise = distribution(generator);

	return x + noise;
}