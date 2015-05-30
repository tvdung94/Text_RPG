#ifndef MAP
#define MAP
class Map {
public:
	Map();
	~Map();
	int getPosX();
	int getPosY();
	bool setPosXY(int PosX, int PosY);
private:
	int PosX;
	int PosY;
};
#endif