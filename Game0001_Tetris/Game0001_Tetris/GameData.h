//============================
// Include guard
#ifndef _GAME_DATA_
#define _GAME_DATA_

//============================
// Include dependencies
#include <vector>
#include <string>

//============================

	// Game Data
	// -- Game Field
	const int mapHeight = 20;
	const int mapWidth = 10;

	extern int map[mapHeight][mapWidth];

	// -- Tetris figures
	struct Point { int x, y; }; 
	extern Point a[4], b[4];// RealPos, SavePos (Reset changes)

	extern int figures[7][4];

	// Game Data processing
	bool Check();


#endif // _GAME_DATA_
