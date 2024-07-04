#pragma once
#include "Include.h"
#define MAX 100

class Snake
{
public:
	int Length = 0;
	bady mbady[MAX];

	int state;
	bool life = true;

	
	void Update()
	{
		if (life == true)
		{
			int hx = mbady[0].x;
			int hy = mbady[0].y;
			if (IsKey(VK_RIGHT) && state != 2)
				state = 1;
			if (IsKey(VK_LEFT) && state != 1)
				state = 2;
			if (IsKey(VK_UP) && state != 4)
				state = 3;
			if (IsKey(VK_DOWN) && state != 3)
				state = 4;
			if (state == 1 && hx < 78)
				hx += 2;
			if (state == 2 && hx>0)
				hx -= 2;
			if (state == 3 && hy > 0)
				hy--;
			if (state == 4 && hy < 24)
				hy++;

			mbady[0].move(hx, hy);
			for (int i = 1; i <= Length; i++)
			{
				mbady[i].move(mbady[i - 1].bx, mbady[i - 1].by);
			}
			if (mbady[0].bx == 78 || mbady[0].bx == 0 || mbady[0].by ==24 || mbady[0].by == 0)
				life = false;
		}
	}
	void Draw()
	{
		if (life == true)
		{
			for (int i = 0; i <= Length; i++)
			{
				mbady[i].Draw();
			}
		}
	}
	void eat(int x_,int y_)
	{
		if (life == true)
		{
			if (mbady[0].x == x_ && mbady[0].y == y_)
				Length++;
		}
	}
};