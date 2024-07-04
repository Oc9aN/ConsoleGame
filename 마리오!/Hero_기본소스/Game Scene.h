#pragma once
#include "Include.h"

class GameScene:public cScene
{	
	Chero player;
	bullet Bullet;

	virtual void Enter();

	virtual void Update();

	virtual void Draw();

	virtual void Exit();
};