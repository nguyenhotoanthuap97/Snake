#include "SnakeClass.h"

SnakeClass::SnakeClass()
{
	Coord temp;
	temp.setX(36);
	temp.setY(12);
	this->Node.push_back(temp);
	for (int i = 0; i < 8; i++)
	{
		temp.setX(37 + i);
		this->Node.push_back(temp);
	}
}


SnakeClass::~SnakeClass()
{
	this->Node.clear();
}

vector<Coord> SnakeClass::getNode()
{
	return this->Node;
}

void SnakeClass::setNode(vector<Coord>& n)
{
	this->Node = n;
}

void SnakeClass::lengthIncrease()
{
	Coord temp;
	if (this->Node[this->Node.size() - 2].getX() == this->Node[this->Node.size() - 1].getX())
	{
		temp.setX(this->Node[this->Node.size() - 1].getX());
		if (this->Node[this->Node.size() - 2].getY() > this->Node[this->Node.size() - 1].getY())
		{
			temp.setY(this->Node[this->Node.size() - 1].getY() - 1);
		}
		else
		{
			temp.setY(this->Node[this->Node.size() - 1].getY() + 1);
		}
	}
	else
	{
		temp.setY(this->Node[this->Node.size() - 1].getY());
		if (this->Node[this->Node.size() - 2].getX() > this->Node[this->Node.size() - 1].getX())
		{
			temp.setX(this->Node[this->Node.size() - 1].getX() - 1);
		}
		else
		{
			temp.setX(this->Node[this->Node.size() - 1].getX() + 1);
		}
	}
	this->Node.push_back(temp);
}

int SnakeClass::move(Food& f, Obstacle& obs)
{
	int ch = 0;
	int d = 3;
	int Score = 0;
	fflush(stdin);
	
	while (1)
	{
		f.draw();
		obs.draw();
		if (kbhit())
		{
			ch = getch();
			if (ch == 224)
			{
				fflush(stdin);
				ch = getch();
				switch (ch)
				{
				case 72:
					if (d == 2)
						break;
					d = 1;
					break;
				case 80:
					if (d == 1)
						break;
					d = 2;
					break;
				case 75:
					if (d == 4)
						break;
					d = 3;
					break;
				case 77:
					if (d == 3)
						break;
					d = 4;
					break;
				}
			}
		}
		
		this->draw();
		Sleep(70 - (this->Node.size() - 9) * 2);
		this->erase();

		for (int i = this->Node.size() - 1; i >= 1; i--)
		{
			this->Node[i].setX(this->Node[i - 1].getX());
			this->Node[i].setY(this->Node[i - 1].getY());
		}

		switch (d)
		{
		case 1: //Up
			this->Node[0].setY(this->Node[0].getY() - 1);
			break;
		case 2: //Down
			this->Node[0].setY(this->Node[0].getY() + 1);
			break;
		case 3: //Left
			this->Node[0].setX(this->Node[0].getX() - 1);
			break;
		case 4: //right
			this->Node[0].setX(this->Node[0].getX() + 1);
			break;
		}

		if (isHit(obs))
			return Score;
		if (this->Node[0].getX() == f.getLocate().getX() && this->Node[0].getY() == f.getLocate().getY())
		{
			this->lengthIncrease();
			Score++;
			f.randomLocate(obs);
			f.draw();
		}
	}
}

void SnakeClass::draw()
{
	gotoXY(this->Node[0].getX(), this->Node[0].getY());
	cout << (char)153;
	for (int i = 1; i < this->Node.size(); i++)
	{
		gotoXY(this->Node[i].getX(), this->Node[i].getY());
		cout << (char)254;
	}
}

void SnakeClass::erase()
{
	gotoXY(this->Node[this->Node.size() - 1].getX(), this->Node[this->Node.size() - 1].getY());
	cout << ' ';
}

bool SnakeClass::isHit(Obstacle& obs)
{
	if (this->Node[0].getX() > 78 || this->Node[0].getX() < 1 || this->Node[0].getY() > 23 || this->Node[0].getY() < 1)
	{
		return true;
	}

	for (int i = 1; i < this->Node.size(); i++)
	{
		if (this->Node[0].getX() == this->Node[i].getX() && this->Node[0].getY() == this->Node[i].getY())
		{
			return true;
		}
	}

	for (int i = 0; i < obs.getObs().size(); i++)
	{
		if (this->getNode()[0].getX() >= obs.getObs()[i].getX() - 1 && this->getNode()[0].getX() <= obs.getObs()[i].getX() + 1 && this->getNode()[0].getY() >= obs.getObs()[i].getY() - 1 && this->getNode()[0].getY() <= obs.getObs()[i].getY() + 1)
		return true;
	}

	return false;
}