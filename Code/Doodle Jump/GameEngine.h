//================================
// Include guard
#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

//================================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <WinUser.h>
#include <string>

// -- Headers
#include "GameObject.h"
#include "Player.h"
#include "Platform.h"

// -- Namespaces
using namespace sf;
using namespace std;

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
	int		maxHeight;

	Font	scoreFont;
	Text	score;
	// -- Game Objects
	Player		playerClone;
	Player		player;
	int			currentPlatform;
	Platform	platforms[10];
	// -- Camera
	View view;
protected:
public:
	RenderWindow	*window;
	float			deltaTime;
	// Methods
private:
	void	LoadImages();
	int		UserInput();
protected:
public:
	GameEngine();
	void Update();
	void Draw();
	bool CheckGameStatus();
};

#endif // _GAME_ENGINE_