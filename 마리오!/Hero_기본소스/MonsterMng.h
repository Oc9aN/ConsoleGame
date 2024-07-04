#pragma once

#include "Include.h"

class MonsterMng
{
private:
	static MonsterMng* instance;
public:
	static MonsterMng* Getinstance()
	{
		if (instance == NULL)
		{
			instance = new MonsterMng();
		}
		return instance;
	}
	Monster monster[10];

	MonsterMng()
	{
		for (int i = 0; i < 10; i++)
		{
			monster[i] = Monster();
		}
	}

	void Create(int x,int y)
	{
		for (int i = 0; i < 10; i++)
		{
			if (monster[i].state == false)
			{
				monster[i].Create_Mon(x, y);
				break;
			}
		}
	}
	void update(int offset)
	{
		for (int i = 0; i < 10; i++)
		{
			if (monster[i].state == true)
			{
				monster[i].update_Mon(offset);
			}
		}
	}
	void Draw(int offset)
	{
		for (int i = 0; i < 10; i++)
		{
			if (monster[i].state == true)
			{
				monster[i].Draw_Mon(offset);
			}
		}
	}
	Monster* Crash(int x, int y)
	{
		for (int i = 0; i < 10; i++)
		{
			if (monster[i].state == true)
			{
				if (monster[i].Monster_Crash(x, y) == true)
					return &monster[i];
			}
		}
		return NULL;
	}
};