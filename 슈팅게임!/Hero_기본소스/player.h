#include "include.h"
#include "mom.h"
#pragma once

class Cplayer :public mom
{
public:
	Cplayer()
	{
		x = 24;
		y = 20;
	}
	virtual void Draw()
	{
		DrawCharEx3(x , y, '!', WHITE, CYAN);
		DrawCharEx3(x + 1,y, '+', WHITE, BROWN);
		DrawCharEx3(x + 2,y, '!', WHITE, CYAN);
	}
	virtual void UPdate()
	{
		if (IsKey(VK_UP) && y > 0)
		{
			y -= 1;
			Draw();
		}
		if (IsKey(VK_DOWN) && y < 24)
		{
			y += 1;
			Draw();
		}
		if (IsKey(VK_LEFT) && x > 0)
		{
			x -= 1;
			Draw();
		}
		if (IsKey(VK_RIGHT) && x < 47)
		{
			x += 1;
			Draw();
		}
		else
		{
			Draw();
		}
	}
};