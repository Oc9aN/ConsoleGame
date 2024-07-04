#include "Include.h"
#include "mom.h"
#include <Windows.h>
#pragma once
char cEffect[3][3][3] = { { { ' ',' ',' ' },
{ ' ','*',' ' },
{ ' ',' ',' ' } },
{ { ' ','*',' ' },
{ '*','*','*' },
{ ' ','*',' ' } },
{ { '*',' ','*' },
{ ' ',' ',' ' },
{ '*',' ','*' } } };

class Ceffect :public mom
{
private:
	int num;
	int count;
public:
	Ceffect()
	{
		x = 0;
		y = 0;
		dead = true;
		num = 0;
	}
	void Create_Effect(int x1, int y1)
	{
		for (int i = 0; i < 25; i++)
		{
			if (dead == true)
			{
				x = x1;
				y = y1;
				dead = false;
				num = 0;
				count = GetTickCount();
				break;
			}
		}
	}
	void UPdate_Effect()
	{
		for (int i = 0; i < 25; i++)
		{
			if (dead == false && GetTickCount() - count >= 130)
			{
				num++;
				count = GetTickCount();

				if (num >= 3)
				{
					dead = true;
				}
			}
		}
	}

	void Draw_Effect()
	{
		for (int k = 0; k < 25; k++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (dead == false)
					{
						DrawCharEx3(x + j - 1, y + i - 1, cEffect[num][i][j], rand() % COLOR_ALL, BLACK);
					}
				}
			}
		}
	}
};