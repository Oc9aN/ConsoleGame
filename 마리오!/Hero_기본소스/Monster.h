#pragma once

class Monster
{
public:
	int x;
	int y;
	int count = GetTickCount();

	bool state = false;
	E_MOVE_M move;

	void update_Mon(int offset);

	void Draw_Mon(int offset);

	void Create_Mon(int x_, int y_);

	bool Monster_Crash(int x_, int y_);
};