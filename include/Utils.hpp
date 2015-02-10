#ifndef UTILS_HPP
#define UTILS_HPP
#include <random>

class Utils
{	
public:
	static void init();
	static double add_noise(double level, double x);
	static double sample_uniform(double from, double to);	

private:
	Utils();
	~Utils();

	static std::default_random_engine generator;
};



#endif