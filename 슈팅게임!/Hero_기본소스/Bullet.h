#include "include.h"
#include "player.h"
#include "mom.h"
#pragma once
class bullet :public mom
{
private:
	int count_bullet;
public:
	void Setdead(int _dead)
	{
		dead = _dead;
	}
	bullet()
	{
		x = 0;
		y = 0;
		dead = 0;
		count_bullet = GetTickCount();
	}
	void create_Bullet(int x1, int y1)
	{
		dead = 1;
		x = x1;
		y = y1;
	}
	virtual void UPdate()
	{
		if (dead == 1)
		{
			y--;
			if (y < 0)
				dead = 0;
		}
	}
	virtual void Drow()
	{
		if (dead == 1)
		{
			DrawCharEx3(x + 1, y, '+', WHITE, LIGHTMAGENTA);
		}
	}
};