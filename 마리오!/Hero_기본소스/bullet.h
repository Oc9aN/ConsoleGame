#pragma once

class bullet
{
public:
	int x;
	int y;
	bool life_BULL = DEAD;

	void create_BULL(int x_,int y_);

	void update_BULL(int offset);

	void draw_BULL();
};