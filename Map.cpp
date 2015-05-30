#include <iostream>
#include "Map.h"

using namespace std;

Map::Map() {
	PosX = 0;
	PosY = 0;
}

Map::~Map() {
	delete this;
}

int Map::getPosX() {
	return PosX;
}

int Map::getPosY() {
	return PosY;
}

bool Map::setPosXY(int PosX, int PosY) {
	if (this->PosX + PosX >= 0 && this->PosY + PosY >= 0 && this->PosX + PosX <=100 && this->PosY + PosY <=100) {
		this->PosX += PosX;
		this->PosY += PosY;
		cout << "Current position: " << this->getPosX() << " " << this->getPosY() << endl;
		return true;
	}
	cout << "You are at an edge of the map. Cant move further" << endl;
	return false;
}