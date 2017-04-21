#include "Food.h"


Food::Food()
{
	this->Locate.setX(0);
	this->Locate.setY(0);
}

Food::Food(Obstacle& obs)
{
	int xtemp = 0;
	int ytemp = 0;
	xtemp = rand() % 77 + 1;
	ytemp = rand() % 22 + 1;

	while (isSamePos(obs, xtemp, ytemp))
	{
		xtemp = rand() % 77 + 1;
		ytemp = rand() % 22 + 1;
	}

	this->Locate.setX(xtemp);
	this->Locate.setY(ytemp);
}


Food::~Food()
{
	this->Locate.setX(0);
	this->Locate.setY(0);
}

Coord Food::getLocate()
{
	return this->Locate;
}

void Food::setLocate(Coord& lo)
{
	this->Locate = lo;
}

void Food::randomLocate(Obstacle& obs)
{
	int xtemp = 0;
	int ytemp = 0;
	xtemp = rand() % 77 + 1;
	ytemp = rand() % 22 + 1;

	while (isSamePos(obs, xtemp, ytemp))
	{
		xtemp = rand() % 77 + 1;
		ytemp = rand() % 22 + 1;
	}

	this->Locate.setX(xtemp);
	this->Locate.setY(ytemp);
}

void Food::draw()
{
	gotoXY(this->Locate.getX(), this->Locate.getY());
	cout << (char)229;
}

bool isSamePos(Obstacle& Obs, int x, int y)
{
	for (int i = 0; i < Obs.getObs().size(); i++)
	{
		if (x >= Obs.getObs()[i].getX() - 1 && x <= Obs.getObs()[i].getX() + 1 && y >= Obs.getObs()[i].getY() - 1 && y <= Obs.getObs()[i].getY() + 1)
			return true;
	}
	return false;
}