#pragma once

class mom
{
public:
	int x;
	int y;
	bool dead;

	virtual void UPdate(){}
	virtual void Draw(){}
	int GetX()
	{
		return x;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	int GetY()
	{
		return y;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	int Getdead()
	{
		return dead;
	}
	void Setdead(int _dead)
	{
		dead = _dead;
	}
	
};