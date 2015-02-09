#include <iostream>
#include <opencv2/opencv.hpp>

#include "World.hpp"

using namespace cv;
using std::cout;
using std::endl;



const int WORLD_HEIGHT = 500;
const int WORLD_WIDTH = 500;
std::vector< std::vector<int> > maze_data = 
	{std::vector<int>{ 1, 1, 0, 0, 2, 0, 0, 0, 0, 1 },
 	 std::vector<int>{ 1, 2, 0, 0, 1, 1, 0, 0, 0, 0 },
 	 std::vector<int>{ 0, 1, 1, 0, 0, 0, 0, 1, 0, 1 },
 	 std::vector<int>{ 0, 0, 0, 0, 1, 0, 0, 1, 1, 2 },
 	 std::vector<int>{ 1, 1, 0, 1, 1, 2, 0, 0, 1, 0 },
 	 std::vector<int>{ 1, 1, 1, 0, 1, 1, 1, 0, 2, 0 },
 	 std::vector<int>{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
 	 std::vector<int>{ 1, 2, 0, 1, 1, 1, 1, 0, 0, 0 },
 	 std::vector<int>{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
 	 std::vector<int>{ 0, 0, 1, 0, 0, 2, 1, 1, 1, 0 }};
int main(int argc, char const *argv[])
{
	Mat maze_img(WORLD_HEIGHT, WORLD_WIDTH, CV_8UC3);

	cout << "World" << endl;
	
	World world(maze_data, WORLD_WIDTH, WORLD_HEIGHT);

	cout << "While" << endl;
	char key;
	do
	{
		world.DrawWorld(maze_img);

		imshow("Particle Filter", maze_img);
		key = waitKey(10);
	}
	while(key != 'q');
	return 0;
}