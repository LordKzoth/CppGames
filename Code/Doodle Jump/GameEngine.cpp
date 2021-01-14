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

int GameEngine::UserInput() {
	Event event;
	while (window->pollEvent(event)) {
		// Close window
		if (event.type == Event::Closed) {
			window->close();
		}
	}

	int _xDirection = 0;
	if (GetKeyState('A') & 0x8000 || GetKeyState(VK_LEFT) & 0x8000) { //event.key.code == Keyboard::A || event.key.code == Keyboard::Left) {
		_xDirection = -1;
	}
	else if (GetKeyState('D') & 0x8000 || GetKeyState(VK_RIGHT) & 0x8000) { //event.key.code == Keyboard::D || event.key.code == Keyboard::Right) {
		_xDirection = 1;
	}
	else {
		_xDirection = 0;
	}

	return _xDirection;
}

// -- Public
GameEngine::GameEngine() {
	srand(time(0));

	LoadImages();
	isGameOver = false;
	
	playerClone = Player();
	player = Player();
	currentPlatform = 0;
	for (int i = 0; i < 10; i++) {
		int platformType = rand() % 3;
		platforms[i] = Platform(platformType, i);
	}

	deltaTime = 0;

	view = View(FloatRect(0, 0, 256, 512));
	maxHeight = player.GetPosition().y;

	scoreFont.loadFromFile("fonts/CyrilicOld.TTF");
	score.setFont(scoreFont);
	score.setString(to_string(0));
}

void GameEngine::Update() {
	// User Input
	int _xDirection = UserInput();

	// Jumping
	// -- Set jump duration
	if (player.jumpTimer >= 0.3) {
		player.jumpTimer = 0;
		player.jumpDirection = 1;
	}
	else if (player.jumpDirection == -1) {
		player.jumpTimer += deltaTime;
	}

	// -- Check intersections with platform
	if (player.GetIntersections(platforms, 10) && player.jumpDirection == 1) {
		player.jumpDirection = -1;
		player.jumpTimer = 0;
	}

	// Movement (Timer is Movement speed)
	if (player.movementTimer >= 0.0025) {
		// X
		// -- Calculate new Position
		playerClone.Move(_xDirection, 0);

		// -- Change real Position
		if (playerClone.GetPosition().x >= 0 && playerClone.GetPosition().x <= (256 - playerClone.GetWidth())) {
			player.Move(_xDirection, 0);
		}
		else {
			playerClone.SetPosition(player.GetPosition());
		}

		// Y
		player.movementTimer = 0;
		player.Move(0, player.jumpDirection);
	}
	else {
		player.movementTimer += deltaTime;
	}

	// Move camera
	if (player.GetPosition().y < maxHeight + (300 - (player.GetHeight() + 10))) {
		maxHeight = player.GetPosition().y - (300 - (player.GetHeight() + 10));
		spriteBackground.setPosition(0, maxHeight);

		score.setPosition(4, maxHeight);
		score.setString(to_string(-maxHeight));

		if (platforms[currentPlatform].GetPosition().y > maxHeight + (300 - (player.GetHeight() + 10)) + 250) {
			platforms[currentPlatform].SetNewPos();
			currentPlatform++;
			if (currentPlatform >= 10) currentPlatform = 0;
		}
	}
	view.setCenter(256 / 2, 512 / 2 + maxHeight);
	window->setView(view);
}

void GameEngine::Draw() {
	window->clear(Color::White);
	window->draw(spriteBackground);

	// Platforms
	for (int i = 0; i < 10; i++) {
		switch (platforms[i].GetImageID())
		{
			default:
			case 1: {
				spritePlatform001.setPosition(platforms[i].GetPosition().x, platforms[i].GetPosition().y);
				window->draw(spritePlatform001);
				break;
			}
			case 2: {
				spritePlatform002.setPosition(platforms[i].GetPosition().x, platforms[i].GetPosition().y);
				window->draw(spritePlatform002);
				break;
			}
			case 3: {
				spritePlatform003.setPosition(platforms[i].GetPosition().x, platforms[i].GetPosition().y);
				window->draw(spritePlatform003);
				break;
			}
		}
	}

	// Player
	spritePlayer.setPosition(player.GetPosition().x, player.GetPosition().y);
	window->draw(spritePlayer);

	window->draw(score);

	window->display();
}

bool GameEngine::CheckGameStatus() {
	if (player.GetPosition().y > maxHeight + (300 - (player.GetHeight() + 10)) + 250) {
		isGameOver = true;
	}

	return isGameOver;
}