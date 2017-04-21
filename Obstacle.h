#pragma once

#include "Coord.h"

class Obstacle
{
	vector<Coord> Obs;
public:
	Obstacle();
	~Obstacle();
	vector<Coord> getObs();
	void setObs(vector<Coord>&);
	void draw();
};

