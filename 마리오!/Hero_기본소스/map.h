class Cmap
{
private:
	static Cmap* mapinstance;
	int y;
	int x;
public:
	static Cmap* Getmapinstance()
	{
		if (mapinstance == NULL)
		{
			mapinstance = new Cmap();
		}
		return mapinstance;
	}
	Tile M_map[160][25];
	void file_road();

	void map_set(int _x);

	~Cmap();
};
