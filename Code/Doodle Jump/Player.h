//================================
// Include guard
#ifndef _PLAYER_
#define _PLAYER_

//================================
// Include dependencies
#include "GameObject.h"
#include "Platform.h"

//================================
// Class declaration

class Player : public GameObject {
	// Fields
private:
protected:
public:
	int		jumpDirection;
	float	jumpTimer;
	float	movementTimer;
	// Methods
private:
protected:
public:
	Player();
	bool GetIntersections(Platform _platforms[], int _count);
};

#endif // !_PLAYER_
