#include "Include.h"

void bullet::create_BULL(int x_, int y_)
{
	life_BULL = LIFE;
	x = x_;
	y = y_;
}
void bullet::update_BULL(int offset)
{	
	if(life_BULL == LIFE)
		x++;
	if (Cmap::Getmapinstance()->M_map[x + offset][y].tile == WALL || Cmap::Getmapinstance()->M_map[x + offset][y].tile == BROKEN_WALL)
		life_BULL = DEAD;
	Monster* monster = MonsterMng::Getinstance()->Crash(x+offset,y);
	if (monster != NULL)
	{
		life_BULL = DEAD;
	}
}
void bullet::draw_BULL()
{
	if(life_BULL == LIFE)
		DrawCharEx3(x, y, '*', BLACK, LIGHTCYAN);
}