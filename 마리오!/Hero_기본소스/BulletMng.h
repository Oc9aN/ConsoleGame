#pragma once
#include "Include.h"

class BulletMng
{
private:
	static BulletMng* instance;
public:
	static BulletMng* Getinstance()
	{
		if (instance == NULL)
			instance = new BulletMng();
		return instance;
	}
	bullet Bullet[5];

	BulletMng()
	{
		for (int i = 0; i < 5; i++)
		{
			Bullet[i] = bullet();
		}
	}

	void Create(int x, int y)
	{
		for (int i = 0; i < 5; i++)
		{
			if (Bullet[i].life_BULL == DEAD)
			{
				Bullet[i].create_BULL(x, y);
				break;
			}
		}
	}

	void update(int offset)
	{
		for (int i = 0; i < 5; i++)
		{
			if (Bullet[i].life_BULL == LIFE)
			{
				Bullet[i].update_BULL(offset);
			}
		}
	}

	void Draw()
	{
		for (int i = 0; i < 5; i++)
		{
			if (Bullet[i].life_BULL == LIFE)
			{
				Bullet[i].draw_BULL();
			}
		}
	}
};