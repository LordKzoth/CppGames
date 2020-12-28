#include "GameData.h"

int map[mapHeight][mapWidth] = { 0 };

// -- Tetris figures
Point a[4], b[4]; // RealPos, SavePos (Reset changes)

int figures[7][4] = {
	3, 5, 7, 9,	// I
	2, 4, 5, 7,	// Z
	3, 5, 4, 6,	// S
	3, 5, 4, 7,	// T
	2, 3, 5, 7,	// L
	3, 5, 7, 6,	// J
	2, 3, 4, 5, // O
};

bool Check() {
	for (int i = 0; i < 4; i++) {
		if (a[i].x < 0
			|| a[i].x >= mapWidth
			|| a[i].y >= mapHeight)		return false;
		else if (map[a[i].y][a[i].x])	return false;
	}
	return true;
}