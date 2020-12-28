//================================
// Include guard
#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

//================================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>

// -- Namespaces
using namespace sf;

//================================
// Class declaration

class GameEngine {
	// Fields
private:
	// -- Textures
	Texture textureBackground;
	Texture texturePlatforms;
	Texture texturePlayer;
	// -- Sprites
	Sprite	spriteBackground;	// Image ID = 0
	Sprite	spritePlatform001;	// Image ID = 1
	Sprite	spritePlatform002;	// Image ID = 2
	Sprite	spritePlatform003;	// Image ID = 3
	Sprite	spritePlayer;		// Image ID = 4
	// -- Game Data
	bool	isGameOver;
protected:
public:
	RenderWindow *window;
	// Methods
private:
	void LoadImages();
	void UserInput();
protected:
public:
	GameEngine();
	void Update();
	void Draw();
	bool CheckGameStatus();
};

#endif // _GAME_ENGINE_