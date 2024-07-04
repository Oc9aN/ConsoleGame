#include "Include.h"

void Cmap::file_road()
{
	FILE* file = fopen("map1.txt", "r");
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 160; x++)
		{
			char tileNum;
			fscanf(file, "%c", &tileNum);
			if (tileNum == '1')
			{
				M_map[x][y].tile = WALL;
				M_map[x][y].x = x;
				M_map[x][y].y = y;
			}
			else if (tileNum == '0')
			{
				M_map[x][y].tile = BLANK;
				M_map[x][y].x = x;
				M_map[x][y].y = y;
			}
			else if (tileNum == '2')
			{
				M_map[x][y].tile = BROKEN_WALL;
				M_map[x][y].x = x;
				M_map[x][y].y = y;
			}
			else if (tileNum == 'M')
			{
				M_map[x][y].tile = BLANK;
				M_map[x][y].x = x;
				M_map[x][y].y = y;

				MonsterMng::Getinstance()->Create(x, y);
			}
		}
	}
	fclose(file);
}

void Cmap::map_set(int _x)
{
	for (int x = 0; x < 160; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			M_map[x][y].Draw(_x);
			M_map[x][y].UPdate();
		}
	}
}

Cmap::~Cmap()
{
	for (int i = 0; i < 24; i++)
	{
		delete[] M_map[i];
	}
	delete[] M_map;
}