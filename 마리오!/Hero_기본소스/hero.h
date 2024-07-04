class Chero
{
private:
	int offset;
	int x;
	int y;
	int time;
	int count;
	int sp_time;
	int JumpState;
public:
	bool life;
	void Init_he();

	void Draw_he(int x,int y);

	void UPdate_he();

	int getoffset();

	int getx();

	int gety();
};
