#include "Include.h"
#define POWER 4

void Chero::Init_he()
{
	x = 10;
	y = 10;
	offset = 0;
	JumpState = 0;
	life = true;
}

void Chero::Draw_he(int x,int y)
{
	if (life == true)
		DrawCharEx3(x, y, '@', BLACK, LIGHTCYAN);
}

void Chero::UPdate_he()
{
	if (IsKey(VK_SPACE) && JumpState == 0)
	{
		JumpState = 1;
		count = 0;
		time = GetTickCount();
	}
	//!< 올라갈때
	if (JumpState == 1)
	{
		if (count >= POWER || Cmap::Getmapinstance()->M_map[x + offset][y - 1].tile == WALL)
		{
			JumpState = 2;
			count = GetTickCount();
		}
		else if (Cmap::Getmapinstance()->M_map[x + offset][y - 1].tile == BROKEN_WALL)
		{
			Cmap::Getmapinstance()->M_map[x + offset][y - 1].tile = BLANK;
			JumpState = 2;
			count = GetTickCount();
		}
		else
		{
			if (GetTickCount() - time > 30)
			{
				y--;
				count++;
				time = GetTickCount();
			}
		}
	}
	//!< 내려갈때
	else if (JumpState == 2)
	{
		if (Cmap::Getmapinstance()->M_map[x + offset][y + 1].tile == WALL || Cmap::Getmapinstance()->M_map[x + offset][y + 1].tile == BROKEN_WALL)
			JumpState = 0;
		else
		{
			if (GetTickCount() - count > 30)
			{
				y++;
				count = GetTickCount();
			}
		}
	}
	else
	{
		if (Cmap::Getmapinstance()->M_map[x + offset][y + 1].tile == BLANK)
		{
			JumpState = 2;
		}
	}
	if (IsKey(VK_RIGHT) && x < 79 && Cmap::Getmapinstance()->M_map[x + 1 + offset][y].tile == BLANK)
	{
		if (offset >= 79)
		{
			x++;
		}
		else if (x < 20)
		{
			x++;
		}
		if (offset<79)
			offset++;
	}
	if (IsKey(VK_LEFT) && x > 0 && Cmap::Getmapinstance()->M_map[x - 1 + offset][y].tile == BLANK)
	{
		x--;
	}
	if (IsKey(VK_Z))
	{
		BulletMng::Getinstance()->Create(x, y);
	}
}

int Chero::getoffset()
{
	return offset;
}

int Chero::getx()
{
	return x;
}

int Chero::gety()
{
	return y;
}