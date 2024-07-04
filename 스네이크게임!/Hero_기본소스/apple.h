#pragma once
#include "Include.h"

class apple
{
public:
	int x;
	int y;
	bool dead = false;

	void Draw()
	{
		if (dead == true)
			DrawStrEx3(x, y, "›D", RED, WHITE);
	}
	void create()
	{
		if (dead == false)
		{
			srand(time(NULL));

			x = 2*(rand() % 39 + 1);
			y = rand() % 23 + 1;
			dead = true;
		}
	}
	void eat(int x_, int y_)
	{
		if (x == x_&&y == y_)
			dead = false;
	}
};
