//==========================
// Include guard
#ifndef _PLAYER_
#define _PLAYER_

//==========================
// Include dependencies
#include "GameObject.h"

//==========================
// Class declaration
class Player : public GameObject {
	// Fields
private:
	float	movementTimer;
	int		movementSpeed;	// Pixels per second
	float	timeForStep;	// Time that necessary for one step (pixel)
protected:
public:
	// Methods
private:
protected:
public:
	Player();
	bool	UpdateMovementTimer(float _deltaTime);
	int		GetMovementSpeed();
};

#endif // !_PLAYER_
