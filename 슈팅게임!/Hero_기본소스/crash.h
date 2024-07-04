#pragma once
#include "Bullet.h"
#include "monster.h"

void crash_m()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (pMonster[i].x == pBullet[j].x && pMonster[i].y == pBullet[j].y && pMonster[i].dead == 1 && pBullet[j].dead == 1)
			{
				pMonster[i].dead = 0;
				pBullet[j].dead = 0;
			}
		}
	}
}