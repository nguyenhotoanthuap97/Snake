#pragma once

#include "Food.h"


class SnakeClass
{
private:
	vector<Coord> Node;
public:
	SnakeClass();
	~SnakeClass();
	vector<Coord> getNode();
	void setNode(vector<Coord>&);
	void lengthIncrease();
	int move(Food&, Obstacle&);
	void draw();
	void erase();
	bool isHit(Obstacle&);
};

