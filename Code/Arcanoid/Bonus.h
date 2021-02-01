//============================
// Include guard
#ifndef _BONUS_
#define _BONUS_

//============================
// Include dependencies
#include "GameObject.h"

//============================
// Class declaration

class Bonus : public GameObject {
	// Fields
private:
	float	movementTimer;
	int		movementSpeed;		// Pixels per second
	float	timeForStep;		// Time that necessary for one step (pixel)
protected:
public:
	// Methods
private:
protected:
public:
	Bonus();
	Bonus(Point _position, int _index);
	bool UpdateMovementTimer(float _deltaTime);
};

#endif // !_BONUS_
