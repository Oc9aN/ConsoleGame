#pragma once

class cScene
{
public:
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Exit() = 0;
};