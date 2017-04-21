#include "Obstacle.h"


Obstacle::Obstacle()
{
	Coord tempPos;
	for (int i = 0; i < 10; i++)
	{
		tempPos.setX(rand() % 61 + 10);
		tempPos.setY(rand() % 16 + 5);
		while (tempPos.getX() > 33 && tempPos.getX() < 46 && tempPos.getY() > 9 && tempPos.getY() < 15)
		{
			tempPos.setX(rand() % 61 + 10);
			tempPos.setY(rand() % 16 + 5);
		}
		this->Obs.push_back(tempPos);
	}
}


Obstacle::~Obstacle()
{
	this->Obs.clear();
}

vector<Coord> Obstacle::getObs()
{
	return this->Obs;
}

void Obstacle::setObs(vector<Coord>& obs)
{
	this->Obs = obs;
}

void Obstacle::draw()
{
	for (int i = 0; i < this->Obs.size(); i++)
	{
		for (int j = this->Obs[i].getX() - 1; j <= this->Obs[i].getX() + 1; j++)
		{
			for (int k = this->Obs[i].getY() - 1; k <= this->Obs[i].getY() + 1; k++)
			{
				gotoXY(j, k);
				cout << (char)177;
			}
		}
	}
}