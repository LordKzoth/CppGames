//==========================
// Include dependencies
#include "Ball.h"

//==========================
// Other
float ABS(float num) {
	if (num < 0) return num * (-1);
	return num;
}

//==========================
// Definition of Class Methods
Ball::Ball() {
	width = 11;
	height = 11;
	type = GameObjectTypes::Player;

	position.x = 0 - (width / 2);
	position.y = 220 - (height / 2) - (11 + 1);

	isMoving = false;
	movementAngle		= 90;
	movementDirection_X = std::cos(movementAngle * 3.14159265 / 180);
	movementDirection_Y = -std::sin(movementAngle * 3.14159265 / 180);

	movementTimer_X = 0;
	movementTimer_Y = 0;
	movementSpeed = 400;
	timeForStep_X = (movementDirection_X == 0) ? 0 : 1.0f / (movementSpeed * ABS(movementDirection_X));
	timeForStep_Y = (movementDirection_Y == 0) ? 0 : 1.0f / (movementSpeed * ABS(movementDirection_Y));

	isMiss = false;
}

bool Ball::UpdateMovementTimer_X(float _deltaTime) {
	if (timeForStep_X == 0) return false;

	if (movementTimer_X < timeForStep_X) {
		movementTimer_X += _deltaTime;

		if (movementTimer_X >= timeForStep_X) {
			movementTimer_X = 0;
			return true;
		}
	}
	else movementTimer_X = 0;

	return false;
}

bool Ball::UpdateMovementTimer_Y(float _deltaTime) {
	if (timeForStep_Y == 0) return false;
	
	if (movementTimer_Y < timeForStep_Y) {
		movementTimer_Y += _deltaTime;

		if (movementTimer_Y >= timeForStep_Y) {
			movementTimer_Y = 0;
			return true;
		}
	}
	else movementTimer_Y = 0;

	return false;
}

int Ball::GetMovementSpeed() {
	return movementSpeed;
}

GameObject* Ball::GetIntersections(GameObject _gameObjects[], int _size) {
	bool isIntersection;
	for (int s = 0; s < _size; s++) {
		if (!_gameObjects[s].isEnabled) continue;

		isIntersection = true;

		if (position.x > _gameObjects[s].GetPosition().x + _gameObjects[s].GetWidth()
			|| position.x + width < _gameObjects[s].GetPosition().x)
		{
			isIntersection = false;
		}

		if (position.y > _gameObjects[s].GetPosition().y + _gameObjects[s].GetHeight()
			|| position.y + height < _gameObjects[s].GetPosition().y)
		{
			isIntersection = false;
		}

		if (isIntersection) return &_gameObjects[s];
	}

	return nullptr;
}

void Ball::UpdateMovementDirection(bool _isHorizontal, int _angle) {
	// Change Angle
	if (_isHorizontal) {
		movementAngle = 360 - movementAngle;

		if (movementAngle >= 20 && movementAngle <= 340) movementAngle -= _angle;

		if (movementAngle == 360) movementAngle = 0;
	}
	else {
		switch (movementAngle / 90) {
		case 0:
		case 1:
			movementAngle = 180 - movementAngle;
			break;
		case 2:
		case 3:
			movementAngle = 180 + (360 - movementAngle);
			if (movementAngle == 360) movementAngle = 0;
			break;
		}
	}

	// Change movement direction
	movementDirection_X = std::cos(movementAngle * 3.14159265 / 180);
	movementDirection_Y = -std::sin(movementAngle * 3.14159265 / 180);

	timeForStep_X = (movementDirection_X == 0) ? 0 : 1.0f / (movementSpeed * ABS(movementDirection_X));
	timeForStep_Y = (movementDirection_Y == 0) ? 0 : 1.0f / (movementSpeed * ABS(movementDirection_Y));
}