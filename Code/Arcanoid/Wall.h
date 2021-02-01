//===========================
// Include guard
#ifndef _WALL_
#define _WALL_

//===========================
// Include dependencies
#include "GameObject.h"

//===========================
// Class declaration

class Wall : public GameObject {
	// Fields
private:
protected:
public:
	// Methods
private:
protected:
public:
	Wall() {}
	Wall(int _position, bool _rotateWall = false);
};

#endif // !_WALL_
