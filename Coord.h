#pragma once
#include <iostream>
using namespace std;
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <time.h>

class Coord
{
	int x;
	int y;
public:
	Coord();
	~Coord();
	Coord(int, int);
	int getX();
	int getY();
	void setX(int X);
	void setY(int Y);
	void xIncrease();
	void yIncrease();
	void xDecrease();
	void yDecrease();
};

//Goto x y
void gotoXY(int x, int y);