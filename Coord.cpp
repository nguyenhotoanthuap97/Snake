#include "Coord.h"


Coord::Coord()
{
	this->x = 0;
	this->y = 0;
}


Coord::~Coord()
{
	this->x = 0;
	this->y = 0;
}


Coord::Coord(int X, int Y)
{
	this->x = X;
	this->y = Y;
}

int Coord::getX()
{
	return this->x;
}

int Coord::getY()
{
	return this->y;
}

void Coord::setX(int X)
{
	this->x = X;
}

void Coord::setY(int Y)
{
	this->y = Y;
}

void Coord::xIncrease()
{
	this->x++;
}

void Coord::yIncrease()
{
	this->y++;
}

void Coord::xDecrease()
{
	this->x--;
}

void Coord::yDecrease()
{
	this->y--;
}

//Goto x y
void gotoXY(int x, int y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };
	SetConsoleCursorPosition(hStdout, position);
}