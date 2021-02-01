//=========================
// Include dependencies
#include "DeathZone.h"

//=========================
// Definition of Class Methods
DeathZone::DeathZone() {
	width = 512;
	height = 10;

	position.x = -256;
	position.y = 256 - (height / 2);

	type = GameObjectTypes::DeathZone;
}