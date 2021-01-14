//================================
// Include dependencies
#include "Platform.h"

//================================
// Definition of Class Methods
Platform::Platform(int _platformType, int _platformIndex) {
	type = GameObjectTypes::Platform;
	isTrigger = false;

	switch (_platformType)
	{
		default:
		case 0: {
			width = 42;
			height = 10;
			imageID = 1;
			break;
		}
		case 1: {
			width = 30;
			height = 10;
			imageID = 2;
			break;
		}
		case 2: {
			width = 61;
			height = 10;
			imageID = 3;
			break;
		}
	}

	if (_platformIndex == 0) {
		point.x = 128 - width / 2;
	}
	else {
		point.x = rand() % (256 - width);
	}
	point.y = 300 - 75 * _platformIndex;
}

void Platform::SetNewPos() {
	point.x = rand() % (256 - width);
	point.y -= 75 * 10;
}