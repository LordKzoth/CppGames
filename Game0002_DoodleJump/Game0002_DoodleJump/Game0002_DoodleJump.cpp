//===================================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>

// -- Headers
#include "GameEngine.h"

// -- Namespaces
using namespace sf;

//===================================
// Main
int main() {
	bool isGameOver = false;
	RenderWindow window(VideoMode(256, 512), "DoodleClone");
	
	GameEngine gameEngine = GameEngine();
	gameEngine.window = &window;

	while (gameEngine.window->isOpen() && !isGameOver) {
		gameEngine.Update();
		gameEngine.Draw();
		//isGameOver = gameEngine.CheckGameStatus();
	}
}