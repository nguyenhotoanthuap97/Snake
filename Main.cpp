//
//Project Name: Snake
//Author: Nguyen Ho Toan Thu
//Main.cpp
//

#include "SnakeClass.h"

#undef main

//Macro set text's colors
#define setTextColor() HANDLE Color; Color = GetStdHandle(STD_OUTPUT_HANDLE);
#define textColor(...) SetConsoleTextAttribute(Color, __VA_ARGS__);

//Box draw
void boxDraw()
{
	for (int i = 0; i < 78; i++)
		cout << (char)177;
	for (int i = 0; i < 24; i++)
		cout << (char)177 << endl;
	for (int i = 0; i < 79; i++)
		cout << (char)177;
	for (int i = 0; i < 25; i++)
	{
		gotoXY(79, i);
		cout << (char)177;
	}
	gotoXY(0, 0);
}

int main()
{
	setTextColor();
	srand(time(NULL));
	Obstacle obs;
	Food f(obs);
	SnakeClass Snake;
	int Score = 0;
	boxDraw();
	Score = Snake.move(f, obs);
	textColor(12);
	gotoXY(32, 11);
	cout << "    GAME OVER    ";
	textColor(10);
	gotoXY(30, 12);
	cout << "    Your Score: " << Score << "    ";
	textColor(14);
	gotoXY(25, 13);
	cout << "    Press any key to exit...    ";
	getch();
}