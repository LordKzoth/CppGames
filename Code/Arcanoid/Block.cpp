//============================
// Include dependencies
#include "Block.h"

//============================
// Definition of Class Methods
Block::Block() {
	imageID = 0;
}

Block::Block(Point _position, int _imageID) {
	position.x = _position.x;
	position.y = _position.y;

	imageID = _imageID;

	if (imageID < 1 || imageID > 5) isEnabled = false;

	type = GameObjectTypes::Block;

	height = 8;
	width = 16;
}

int Block::GetImadeID() {
	return imageID;
}