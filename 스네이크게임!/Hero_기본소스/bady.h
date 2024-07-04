#pragma once
#include "Include.h"

class bady
{
public:
	int x = 4;
	int y = 3;
	int bx;
	int by;
	void move(int _x, int _y)
	{
		bx = x;
		by = y;
		x = _x;
		y = _y;
	}
	void Draw()
	{
		DrawStrEx3(x, y, "‘¯", BLUE,BLACK);
	}
};