//==================
// Incude guard
#ifndef _BALL_
#define _BALL_

//==================
// Include dependencies
// -- Libraries
#include <cmath>

// -- Headers
#include "GameObject.h"

//==================
class Ball : public GameObject {
	// Fields
private:
	float	movementTimer_X;
	float	movementTimer_Y;
	int		movementSpeed;		// Pixels per second
	float	timeForStep_X;		// Time that necessary for one step (pixel)
	float	timeForStep_Y;		// Time that necessary for one step (pixel)
	int		movementAngle;
protected:
public:
	float	movementDirection_X;
	float	movementDirection_Y;
	bool	isMoving;
	bool	isMiss;
	// Methods
private:
protected:
public:
	Ball();
	bool		UpdateMovementTimer_X(float _deltaTime);
	bool		UpdateMovementTimer_Y(float _deltaTime);
	int			GetMovementSpeed();
	GameObject*	GetIntersections(GameObject _gameObjects[], int _size);
	void		UpdateMovementDirection(bool _isHorizontal, int _angle);
};

#endif // !_BALL_
