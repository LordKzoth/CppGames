//=======================================
// Include dependencies
#include "GameObject.h"

//=======================================
// Definition of Class Methods
GameObject::GameObject() {
	point.x = 0;
	point.y = 0;
	width = 0;
	height = 0;

	type = GameObjectTypes::Nothing;
	imageID = 0;
	isTrigger = false;
}

bool GameObject::GetIntersections(Point _points[], int _widths[], int _heights[], int _count) {
	bool check;
	for (int c = 0; c < _count; c++) {
		check = false;
		if (point.x > _points[c].x + _widths[c]
			|| point.x + width < _points[c].x) check = true;
		if (point.y > _points[c].y + _heights[c]
			|| point.y + height < _points[c].y) check = true;

		if (!check) return true;
	}

	return false;
}

Point GameObject::GetPosition() {
	return point;
}

void GameObject::SetPosition(Point _point) {
	point.x = _point.x;
	point.y = _point.y;
}

int	GameObject::GetImageID() {
	return imageID;
}

void GameObject::Move(int _xDirection, int _yDirection) {
	point.x += _xDirection;
	point.y += _yDirection;
}

int GameObject::GetWidth() {
	return width;
}

int GameObject::GetHeight() {
	return height;
}