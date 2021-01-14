//===============================
// Include dependencies
#include "Player.h"

//===============================
// Definition of Class Methods
Player::Player() {
	jumpDirection = 1;
	jumpTimer = 0;
	movementTimer = 0;

	width = 34;
	height = 32;

	type = GameObjectTypes::Player;
	imageID = 4;
	isTrigger = false;

	point.x = 128 - width / 2;
	point.y = 300 - (height + 10);
}

bool Player::GetIntersections(Platform _platforms[], int _count) {//Point _points[], int _widths[], int _heights[], int _count) {
	bool check;
	for (int c = 0; c < _count; c++) {
		check = false;
		if (point.x > _platforms[c].GetPosition().x + _platforms[c].GetWidth()
			|| point.x + width < _platforms[c].GetPosition().x) check = true;
		if ((point.y + (height / 5)) > _platforms[c].GetPosition().y + _platforms[c].GetHeight()
			|| point.y + height < _platforms[c].GetPosition().y) check = true;

		if (!check) return true;
	}

	return false;
}