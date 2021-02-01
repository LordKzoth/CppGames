//=======================
// Include dependencies
#include "GameEngine.h"

//=======================
// Definition of Class methods
// -- Private methods
void GameEngine::LoadImages() {
	textureBackground.loadFromFile("images/Background.png");
	textureBlocks.loadFromFile("images/Blocks.png");
	textureBall.loadFromFile("images/Ball.png");
	texturePlayer.loadFromFile("images/Player.png");
	textureBonus.loadFromFile("images/Bonus.png");

	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(-256, -256);

	spriteBlock001.setTexture(textureBlocks);
	spriteBlock001.setTextureRect(IntRect(0, 0, 15 + 1, 7 + 1));
	spriteBlock002.setTexture(textureBlocks);
	spriteBlock002.setTextureRect(IntRect(16, 0, 15 + 1, 7 + 1));
	spriteBlock003.setTexture(textureBlocks);
	spriteBlock003.setTextureRect(IntRect(32, 0, 15 + 1, 7 + 1));
	spriteBlock004.setTexture(textureBlocks);
	spriteBlock004.setTextureRect(IntRect(48, 0, 15 + 1, 7 + 1));
	spriteBlock005.setTexture(textureBlocks);
	spriteBlock005.setTextureRect(IntRect(64, 0, 15 + 1, 7 + 1));

	spriteBall.setTexture(textureBall);
	spriteBall.setTextureRect(IntRect(0, 8, 11 + 1, 11 + 1));

	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setTextureRect(IntRect(0, 16, 64 + 1, 15 + 1));

	spriteBonus.setTexture(textureBonus);
	spriteBonus.setTextureRect(IntRect(0, 32, 9 + 1, 17 + 1));
}

void GameEngine::UserInput() {
	Event event;
	while (window->pollEvent(event)) {
		if (event.type == Event::Closed) {
			window->close();
		}

		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Space) {
				ball.isMoving = true;
			}
		}
	}

	if (GetKeyState('A') & 0x8000 || GetKeyState(VK_LEFT) & 0x8000) {
		horizontalInput = -1;
	}
	else if (GetKeyState('D') & 0x8000 || GetKeyState(VK_RIGHT) & 0x8000) {
		horizontalInput = 1;
	}
	else {
		horizontalInput = 0;
	}
}

// -- Public methods
GameEngine::GameEngine(int _currentLevel, int _totalScore, int _bestScore) {
	LoadImages();

	isGameOver = false;
	
	horizontalInput = 0;

	player = Player();
	clonePlayer = Player();
	walls[0] = Wall(-256);
	walls[1] = Wall(256);
	walls[2] = Wall(-256, true);

	cloneBall = Ball();
	ball = Ball();

	deathZone = DeathZone();

	deltaTime = 0;

	gameFont.loadFromFile("fonts/CyrilicOld.TTF");
	startGameText.setFont(gameFont);
	startGameText.setString("To start game press SPACE");

	// Map
	countOfBlocks	= 0;
	currentLevel	= _currentLevel;
	totalScore		= _totalScore;
	bestScore		= _bestScore;

	Point _startPos;
	_startPos.x = -232;
	_startPos.y = -200;

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 30; x++) {
			Point _temp;
			_temp.x = _startPos.x + x * 16;
			_temp.y = _startPos.y + y * 8;

			int _imageID = (int)mapTemplate[currentLevel][y][x] - (int)'0';

			map[y * 30 + x] = Block(_temp, _imageID);
			if (_imageID >= 1 && _imageID <= 5) countOfBlocks++;
		}
	}
}

void GameEngine::Update() {
	bool _bonusWasCreated = false;
	bool _spawnChance = (rand() % 10) == 0;

	UserInput();

	// Move player
	if (horizontalInput != 0 && ball.isMoving) {
		if (player.UpdateMovementTimer(deltaTime)) {
			clonePlayer.Move(horizontalInput, 0);
			if (clonePlayer.GetIntersections(walls, 2)) {
				clonePlayer.SetPosition(player.GetPosition());
			}
			else {
				player.Move(horizontalInput, 0);
			}
			
		}
	}
	
	// Ball Movement
	// -- Move Ball (X)
	if (ball.isMoving) {
		if (ball.UpdateMovementTimer_X(deltaTime)) {

			int movementDirection_X =
				(ball.movementDirection_X == 0) ? 0 :
				(ball.movementDirection_X > 0) ? 1 : -1;

			cloneBall.Move(movementDirection_X, 0);

			bool _intersectionWithBlock = false;
			for (int i = 0; i < 15 * 30; i++) {
				if (map[i].GetIntersections(new GameObject[1]{ cloneBall }, 1)) {
					_intersectionWithBlock = true;
					map[i].isEnabled = false;
					countOfBlocks--;
					if (countOfBlocks == 0) isGameOver = true;
					totalScore += 10;

					if (!_bonusWasCreated && _spawnChance) {
						Point _bonusPos;
						_bonusPos.x = map[i].GetPosition().x + 3;
						_bonusPos.y = map[i].GetPosition().y;

						bonuses.push_back(new Bonus(_bonusPos, bonuses.size() - 1));
						_bonusWasCreated = true;
					}
				}
			}
			
			if (cloneBall.GetIntersections(walls, 3) != nullptr && !ball.isMiss) {
				// Change Movement Direction (Sin and Cos)
				ball.UpdateMovementDirection(false, -2 + rand() % 5);

				// Setting position for clone as for ball
				cloneBall.SetPosition(ball.GetPosition());
			}
			else if (cloneBall.GetIntersections(new GameObject[1]{ player }, 1) != nullptr && !ball.isMiss) {
				// Setting position for clone as for ball
				cloneBall.SetPosition(ball.GetPosition());
			}
			else if (_intersectionWithBlock && !ball.isMiss) {
				// Change Movement Direction (Sin and Cos)
				ball.UpdateMovementDirection(false, -2 + rand() % 5);

				// Setting position for clone as for ball
				cloneBall.SetPosition(ball.GetPosition());
			}
			else {
				ball.Move(movementDirection_X, 0);
			}

		}
	}
	// -- Move Ball (Y)
	if (ball.isMoving) {
		if (ball.UpdateMovementTimer_Y(deltaTime)) {

			int movementDirection_Y =
				(ball.movementDirection_Y == 0) ? 0 :
				(ball.movementDirection_Y > 0) ? 1 : -1;

			cloneBall.Move(0, movementDirection_Y);

			bool _intersectionWithBlock = false;
			for (int i = 0; i < 15 * 30; i++) {
				if (map[i].GetIntersections(new GameObject[1]{ cloneBall }, 1)) {
					_intersectionWithBlock = true;
					map[i].isEnabled = false;
					countOfBlocks--;
					if (countOfBlocks == 0) isGameOver = true;
					totalScore += 10;
					
					if (!_bonusWasCreated && _spawnChance) {
						Point _bonusPos;
						_bonusPos.x = map[i].GetPosition().x + 3;
						_bonusPos.y = map[i].GetPosition().y;

						bonuses.push_back(new Bonus(_bonusPos, bonuses.size() - 1));
						_bonusWasCreated = true;
					}
				}
			}

			if (cloneBall.GetPosition().y > player.GetPosition().y - 11) ball.isMiss = true;

			if (cloneBall.GetIntersections(walls, 3) != nullptr && !ball.isMiss) {
				// Change Movement Direction
				ball.UpdateMovementDirection(true, -2 + rand() % 5);

				// Setting position for clone as for ball
				cloneBall.SetPosition(ball.GetPosition());
			}
			else if (cloneBall.GetIntersections(new GameObject[1]{ player }, 1) != nullptr && !ball.isMiss) {
				int _angleOffset = (player.GetPosition().x + player.GetWidth() / 2 
					- (ball.GetPosition().x + ball.GetWidth() / 2)) / 10;

				// Change Movement Direction
				ball.UpdateMovementDirection(true, _angleOffset * (-5) /*!!!*/);

				// Setting position for clone as for ball
				cloneBall.SetPosition(ball.GetPosition());
			}
			else if (cloneBall.GetIntersections(new GameObject[1]{ deathZone }, 1) != nullptr) {
				isGameOver = true;
			}
			else if (_intersectionWithBlock && !ball.isMiss) {
				// Change Movement Direction
				ball.UpdateMovementDirection(true, -2 + rand() % 5);

				// Setting position for clone as for ball
				cloneBall.SetPosition(ball.GetPosition());
			}
			else {
				ball.Move(0, movementDirection_Y);
			}
		}
	}

	// Bonus movement
	for (int i = 0; i < bonuses.size(); i++) {
		if (bonuses[i]->UpdateMovementTimer(deltaTime)) {
			bonuses[i]->Move(0, 1);

			if (bonuses[i]->GetIntersections(new GameObject[]{ player }, 1)) {
				totalScore += 100;
				int _saveIndex = i;
				delete bonuses[i];
				bonuses.erase(bonuses.begin() + _saveIndex);
			}
			else if (bonuses[i]->GetIntersections(new GameObject[]{ deathZone }, 1)) {
				int _saveIndex = i;
				delete bonuses[i];
				bonuses.erase(bonuses.begin() + _saveIndex);
			}
		}
	}
}

void GameEngine::Draw() {
	window->clear();
	window->draw(spriteBackground);

	spriteBall.setPosition((float)ball.GetPosition().x, (float)ball.GetPosition().y);
	window->draw(spriteBall);

	if (!ball.isMoving) {
		startGameText.setString("To start game press SPACE");
		startGameText.setPosition(-190, -20);
		window->draw(startGameText);
		startGameText.setString("Best Score: " + std::to_string(bestScore));
		startGameText.setPosition(-250, -250);
		window->draw(startGameText);
	}
	else {
		startGameText.setString("Score: " + std::to_string(totalScore));
		startGameText.setPosition(-250, -250);
		window->draw(startGameText);
	}
	

	spritePlayer.setPosition((float)player.GetPosition().x, (float)player.GetPosition().y - 4);
	window->draw(spritePlayer);

	for (int y = 0; y < 15; y++) {
		for (int x = 0; x < 30; x++) {
			if (!map[y * 30 + x].isEnabled) continue;

			switch (map[y * 30 + x].GetImadeID())
			{
			case 1:
				spriteBlock001.setPosition(map[y * 30 + x].GetPosition().x, map[y * 30 + x].GetPosition().y);
				window->draw(spriteBlock001);
				break;
			case 2:
				spriteBlock002.setPosition(map[y * 30 + x].GetPosition().x, map[y * 30 + x].GetPosition().y);
				window->draw(spriteBlock002);
				break;
			case 3:
				spriteBlock003.setPosition(map[y * 30 + x].GetPosition().x, map[y * 30 + x].GetPosition().y);
				window->draw(spriteBlock003);
				break;
			case 4:
				spriteBlock004.setPosition(map[y * 30 + x].GetPosition().x, map[y * 30 + x].GetPosition().y);
				window->draw(spriteBlock004);
				break;
			case 5:
				spriteBlock005.setPosition(map[y * 30 + x].GetPosition().x, map[y * 30 + x].GetPosition().y);
				window->draw(spriteBlock005);
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < bonuses.size(); i++) {
		spriteBonus.setPosition(bonuses[i]->GetPosition().x, bonuses[i]->GetPosition().y);
		window->draw(spriteBonus);
	}

	window->display();
}

bool GameEngine::CheckGameStatus() {

	return isGameOver;
}