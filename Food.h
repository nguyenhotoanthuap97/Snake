#pragma once

#include "Obstacle.h"

class Food
{
private:
	Coord Locate;
public:
	Food();
	~Food();
	Food(Obstacle&);
	Coord getLocate();
	void setLocate(Coord&);
	void randomLocate(Obstacle&);
	void draw();
};

bool isSamePos(Obstacle&, int, int);