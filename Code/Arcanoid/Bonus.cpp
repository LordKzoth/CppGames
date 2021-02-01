//============================
// Include dependencies
#include "Bonus.h"

//============================
// Definition of Class Methods
Bonus::Bonus() {
	movementTimer = 0;
	movementSpeed = 0;
	timeForStep = 0;
}

Bonus::Bonus(Point _position, int _index) {
	movementTimer	= 0;
	movementSpeed	= 600;
	timeForStep		= 1.0f / (movementSpeed);

	position.x = _position.x;
	position.y = _position.y;

	type = GameObjectTypes::Bonus;

	width = 10;
	height = 18;
}

bool Bonus::UpdateMovementTimer(float _deltaTime) {
	if (timeForStep == 0) return false;

	if (movementTimer < timeForStep) {
		movementTimer += _deltaTime;

		if (movementTimer >= timeForStep) {
			movementTimer = 0;
			return true;
		}
	}
	else movementTimer = 0;

	return false;
}