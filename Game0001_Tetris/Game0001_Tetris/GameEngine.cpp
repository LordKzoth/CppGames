//==============================
// Include dependencies
#include "GameEngine.h"
#include "GameData.h"

//==============================
// Definition of Class methods
// -- Private
void GameEngine::LoadImages() {
	// Load Textures
	t1.loadFromFile("images/tiles.png");
	t2.loadFromFile("images/background.png");
	t3.loadFromFile("images/frame.png");

	// Create Sprites
	s.setTexture(t1);
	background.setTexture(t2);
	frame.setTexture(t3);
}

void GameEngine::UserInput() {
	sf::Event event;
	while (window->pollEvent(event)) {
		if (event.type == Event::Closed) window->close();
		if (event.type == Event::KeyPressed) {
			if (event.key.code == Keyboard::Up)			rotate = true;
			else if (event.key.code == Keyboard::Left)	dx = -1;
			else if (event.key.code == Keyboard::Right)	dx = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;
	}
}

// -- Public
GameEngine::GameEngine() {
	LoadImages();

	timer		= 0;
	delay		= 0.3;

	gameFigure = GameFigure();
	gameFigure.CreateNewFigure();
}

void GameEngine::Update() {
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;

	// User Input
	UserInput();

	// Update figure
	// -- Move
	gameFigure.MoveFigure(dx);

	// -- Rotate
	gameFigure.RotateFigure(rotate);

	// Tick
	if (timer > delay) {
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].y += 1;
		}
		if (!Check()) {
			gameFigure.CreateNewFigure();
		}

		timer = 0;
	}

	// Check lines
	int k = mapHeight - 1;
	for (int i = mapHeight - 1; i > 0; i--) {
		int count = 0;
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j]) count++;
			map[k][j] = map[i][j];
		}
		if (count < mapWidth) k--;
	}
	for (int i = 0; i < mapWidth; i++) {
		if (map[0][i]) window->close();
	}

	// Set default values
	dx		= 0;
	rotate	= 0;
	delay	= 0.3;
}

void GameEngine::Draw() {
	window->clear(Color::White);
	window->draw(background);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			if (map[i][j] == 0) continue;

			s.setTextureRect(IntRect(map[i][j] * 18, 0, 18, 18));
			s.setPosition(j * 18, i * 18);
			s.move(28, 31);
			window->draw(s);
		}
	}

	for (int i = 0; i < 4; i++) {
		s.setTextureRect(IntRect(gameFigure.GetColorNum() * 18, 0, 18, 18));
		s.setPosition(a[i].x * 18, a[i].y * 18);
		s.move(28, 31);
		window->draw(s);
	}

	window->draw(frame);
	window->display();
}