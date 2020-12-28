//==============================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>
#include <windows.h>
// -- Headers
#include "GameEngine.h"
// -- Namespaces
using namespace sf;

// =============================
// Main
int main() {
#ifndef _DEBUG
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
#endif
	srand(time(0));

	RenderWindow window(sf::VideoMode(320, 480), "Tetris");

	GameEngine gameEngine = GameEngine();
	gameEngine.window = &window;

	while ((gameEngine.window)->isOpen()) {
		gameEngine.Update();
		gameEngine.Draw();
	}

	return 0;
}