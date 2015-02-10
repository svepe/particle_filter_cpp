#include "World.hpp"	

#include <iostream>
#include "Particle.hpp"

using namespace cv;


World::World(const std::vector<std::vector<int>>& m, int w, int h)
{
	width = w;
	height = h;
	maze_block_size = Size(width / m[0].size(), height / m.size());
	
	maze.resize(m.size());
	for(size_t i = 0; i < maze.size(); ++i)
	{

		maze[i].resize(m[0].size());	
		for(size_t j = 0; j < maze[i].size(); ++j)
		{
			maze[i][j] = m[i][j];
			if(maze[i][j] == 2)
			{
				Point pt = Point(j * maze_block_size.width, i * maze_block_size.height);
				beacons.push_back(pt);
				beacons.push_back(pt + Point(maze_block_size.width, 0));
				beacons.push_back(pt + Point(0, maze_block_size.height));
				beacons.push_back(pt + Point(maze_block_size.width, maze_block_size.height));
			}
		}

	}

	
}

World::~World()
{
}

void World::DrawWorld(cv::Mat& img)
{
	img.setTo(cv::Scalar(255,255,255));
	drawMaze(img);
	drawBeacons(img);
}

void World::drawMaze(cv::Mat& img)
{
	for(size_t i = 0; i < maze.size(); ++i)
	{
		for(size_t j = 0; j < maze.size(); ++j)
		{
			if(maze[i][j])
			{
				Point pt1 = Point(j * maze_block_size.width, i * maze_block_size.height);
				Point pt2 = Point(pt1.x +  maze_block_size.width, pt1.y + maze_block_size.height);
				rectangle(img, pt1, pt2, CV_RGB(0, 0, 0), CV_FILLED);
			}
		}
	}
}

void World::drawBeacons(cv::Mat& img)
{
	for(size_t i = 0; i < beacons.size(); ++i)
		circle(img, beacons[i], 3, CV_RGB(255, 0, 0), CV_FILLED);
}