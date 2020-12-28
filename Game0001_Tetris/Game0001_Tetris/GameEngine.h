//===========================
// Include guard
#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

//===========================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>
#include <time.h>

// -- Headers
#include "GameFigure.h"

// -- Namespaces
using namespace sf;

//===========================
// Class
class GameEngine {
	// Fields
private:
	Texture t1, t2, t3;
	Sprite s, background, frame;
		// 0 - Figures, 
		// 1 - Background,
		// 2 - Frame
	int			dx;
	bool		rotate;
	float		timer;
	float		delay;
	sf::Clock	clock;
	GameFigure	gameFigure;
protected:
public:
	sf::RenderWindow *window;
	// Methods
private:
	void LoadImages();
	void UserInput();
protected:
public:
	GameEngine();
	void Update();
	void Draw();
};

#endif // _GAME_ENGINE_
