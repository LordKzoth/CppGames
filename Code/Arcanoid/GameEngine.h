//========================
// Include guard
#ifndef _GAME_ENGINE_
#define _GAME_ENGINE_

//========================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <WinUser.h>
#include <string>
#include <vector>

// -- Headers
#include "Player.h"
#include "Wall.h"
#include "Ball.h"
#include "DeathZone.h"
#include "Block.h"
#include "GameData.h"
#include "Bonus.h"

// -- Namespaces
using namespace sf;

//========================
// Class declaration
class GameEngine {
	// Fields
private:
	// -- Images
	Texture textureBackground;
	Texture textureBlocks;
	Texture textureBall;
	Texture texturePlayer;
	Texture textureBonus;

	Sprite	spriteBackground;
	Sprite	spriteBlock001;		// Image ID = 1
	Sprite	spriteBlock002;		// Image ID = 2
	Sprite	spriteBlock003;		// Image ID = 3
	Sprite	spriteBlock004;		// Image ID = 4
	Sprite	spriteBlock005;		// Image ID = 5
	Sprite	spriteBall;
	Sprite	spritePlayer;
	Sprite	spriteBonus;
	// -- Game data
	bool isGameOver;
	// -- User Input
	int	horizontalInput;
	// -- GameObjects
	Player player;
	Player clonePlayer;
	Wall walls[3];
	Ball cloneBall;
	Ball ball;
	DeathZone deathZone;
	std::vector <Bonus*> bonuses;
	// -- UI
	Font gameFont;
	Text startGameText;
	// -- Map data
	int		currentLevel;
	Block	map[15 * 30];
protected:
public:
	RenderWindow	*window;
	View			*mainCamera;
	float			deltaTime;
	int				countOfBlocks;
	int				totalScore;
	int				bestScore;
	// Methods
private:
	void LoadImages();
	void UserInput();
protected:
public:
	GameEngine(int _currentLevel, int _totalScore, int _bestScore);
	void Update();
	void Draw();
	bool CheckGameStatus();
};

#endif // !_GAME_ENGINE_
