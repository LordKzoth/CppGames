//====================================
// Include dependencies
#include "GameEngine.h"

//====================================
// Definition of Class Methods
// -- Private
void GameEngine::LoadImages() {
	// Load Textures
	textureBackground.loadFromFile("images/Background.png");
	texturePlatforms.loadFromFile("images/Platforms.png");
	texturePlayer.loadFromFile("images/Player.png");

	// Create Sprites
	// -- Background
	spriteBackground.setTexture(textureBackground);
	// -- Platform 001
	spritePlatform001.setTexture(texturePlatforms);
	spritePlatform001.setTextureRect(IntRect(0, 0, 42, 10));
	// -- Platform 002
	spritePlatform002.setTexture(texturePlatforms);
	spritePlatform002.setTextureRect(IntRect(0, 10, 30, 10));
	// -- Platform 003
	spritePlatform003.setTexture(texturePlatforms);
	spritePlatform003.setTextureRect(IntRect(0, 20, 61, 10));
	// -- Player
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setTextureRect(IntRect(0, 30, 34, 32));
}

void GameEngine::UserInput() {
	Event event;
	while (window->pollEvent(event)) {
		// Close window
		if (event.type == Event::Closed) {
			window->close();
		}
	}
	
}

// -- Public
GameEngine::GameEngine() {
	srand(time(0));

	LoadImages();
	isGameOver = false;
}

void GameEngine::Update() {
	UserInput();
}

void GameEngine::Draw() {
	window->clear(Color::White);
	window->draw(spriteBackground);

	window->display();
}

bool GameEngine::CheckGameStatus() {


	return isGameOver;
}