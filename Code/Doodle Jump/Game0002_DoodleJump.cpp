//===================================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>
#include <Windows.h>

// -- Headers
#include "GameEngine.h"

// -- Namespaces
using namespace sf;

//===================================
// Main
int main() {
#ifndef _DEBUG
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
#endif

	Clock clock;

	bool isGameOver = false;
	RenderWindow window(VideoMode(256, 512), "DoodleClone");
	View view(FloatRect(0, 0, 256, 512));
	
	GameEngine gameEngine = GameEngine();
	gameEngine.window = &window;

	while (gameEngine.window->isOpen() && !isGameOver) {
		gameEngine.deltaTime = clock.restart().asSeconds();
		gameEngine.Update();
		gameEngine.Draw();
		isGameOver = gameEngine.CheckGameStatus();
	}
}