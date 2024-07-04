#pragma once
#include "Include.h"

class Tile
{
public:
	int x;
	int y;
	E_TILE tile;
	void UPdate()
	{

	}
	void Draw(int offset) 
	{
		switch (tile)
		{
		case BLANK:
			DrawCharEx3(x - offset, y, ' ', LIGHTCYAN, LIGHTCYAN);
			break;
		case WALL:
			DrawCharEx3(x - offset, y, ' ', DARKGRAY, DARKGRAY);
			break;
		case BROKEN_WALL:
			DrawCharEx3(x - offset, y, '#', LIGHTRED, DARKGRAY);
			break;
		}
	}
};