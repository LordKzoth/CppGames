//==============================
// Include dependencies
#include "GameObject.h"

//==============================
// Definition of Class methods
GameObject::GameObject() {
	position.x = 0;
	position.y = 0;

	width	= 0;
	height	= 0;

	type = GameObjectTypes::None;

	isEnabled = true;
}

void GameObject::SetPosition(Point _position) {
	position = _position;
}

Point GameObject::GetPosition() {
	return position;
}

int GameObject::GetWidth() {
	return width;
}

int GameObject::GetHeight() {
	return height;
}

void GameObject::Move(int _xDirection, int _yDirection) {
	position.x += _xDirection;
	position.y += _yDirection;
}

bool GameObject::GetIntersections(GameObject _gameObjects[], int _size) {
	if (!isEnabled) return false;

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

		if (isIntersection) return true;
	}

	return false;
}