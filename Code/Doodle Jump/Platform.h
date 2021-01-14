//====================================
// Include guard
#ifndef _PLATFORM_
#define _PLATFORM_

//====================================
// Include dependencies
#include "GameObject.h"

//====================================
// Class declaretion

class Platform : public GameObject {
	// Fields
private:
protected:
public:
	// Methods
private:
protected:
public:
	Platform() {}
	Platform(int _platformType, int _platformIndex);
	void SetNewPos();
};

#endif // _PLATFORM