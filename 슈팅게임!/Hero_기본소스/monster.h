#include <time.h>
#include <windows.h>
#pragma once

class monster :public mom
{
private:
	int mTime;
public:
	monster()
	{
		x = 0;
		y = 0;
		dead = 0;
		mTime = GetTickCount();
	}
	void create_Monster()
	{
		x = rand() % 48 + 1;
		y = 0;
		dead = 1;
		mTime = GetTickCount();
	}
	virtual void UPdate()
	{
		if (GetTickCount() - mTime >= 100)
		{
			y++;
			mTime = GetTickCount();
		}
		if (y > 24)
			dead = 0;
	}
	virtual void Draw()
	{
			if (dead == 1)
			{
				DrawCharEx3(x, y, '@', rand() % COLOR_ALL, BLACK);
			}
	}
};