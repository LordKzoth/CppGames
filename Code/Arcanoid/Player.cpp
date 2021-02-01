//============================
// Include dependencies
#include "Player.h"

//============================
// Definition of Class methods
Player::Player() {
	width	= 64;
	height	= 11;
	type	= GameObjectTypes::Player;

	position.x = 0 - (width / 2);
	position.y = 220 - (height / 2) + 4;

	movementTimer	= 0;
	movementSpeed	= 300;
	timeForStep		= 1.0f / movementSpeed;
}

bool Player::UpdateMovementTimer(float _deltaTime) {
	if (movementTimer < timeForStep) {
		movementTimer += _deltaTime;

		if (movementTimer >= timeForStep) {
			movementTimer = 0;
			return true;
		}
	}

	return false;
}

int Player::GetMovementSpeed() {
	return movementSpeed;
}