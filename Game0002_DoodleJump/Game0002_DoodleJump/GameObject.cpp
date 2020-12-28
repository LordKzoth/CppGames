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

bool GameObject::GetIntersections(Point points[], int widths[], int heights[], int myIndex) {

}

Point GameObject::GetPosition() {
	return point;
}

int	GameObject::GetImageID() {
	return imageID;
}