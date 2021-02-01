//==============================
// Include dependencies
#include "Wall.h"

//==============================
// Definition of Class methods
Wall::Wall(int _position, bool _rotateWall) {
	if (!_rotateWall) {
		width = 10;
		height = 512;

		position.x = _position - (width / 2);
		position.y = -256;
	}
	else {
		width = 512;
		height = 10;

		position.x = -256;
		position.y = _position - (height / 2);
	}
	

	type = GameObjectTypes::Wall;
}