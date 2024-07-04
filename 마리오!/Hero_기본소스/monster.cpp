#include "Include.h"

void Monster::update_Mon(int offset)
{
	if (state == true)
	{
		if (move == RIGHT && state == true)
		{
			if (GetTickCount() - count > 150)
			{
				x++;
				count = GetTickCount();
			}
			if (Cmap::Getmapinstance()->M_map[x + 1][y].tile == WALL)
				move = LEFT;
		}
		else if (move == LEFT && state == true)
		{
			if (GetTickCount() - count > 100)
			{
				x--;
				count = GetTickCount();
			}
			if (Cmap::Getmapinstance()->M_map[x - 1][y].tile == WALL)
				move = RIGHT;
		}
	}
}
void Monster::Draw_Mon(int offset)
{	
	if (state == true)
		DrawCharEx3(x - offset, y, 'M', GREEN, GREEN);
}
void Monster::Create_Mon(int x_,int y_)
{
	x = x_;
	y = y_;
	state = LIFE;
	move = RIGHT;
}

bool Monster::Monster_Crash(int x_,int y_)
{
	if (x == x_ && y == y_)
	{
		return true;
	}
	return false;
}