//==========================
// Include guard
#ifndef _BLOCK_
#define _BLOCK_

//==========================
// Include dependencies
#include "GameObject.h"

//==========================
// Class declaration
class Block : public GameObject {
	// Fields
private:
	int imageID;
protected:
public:
	// Methods
private:
protected:
public:
	Block();
	Block(Point _position, int _imageID);
	int GetImadeID();
};

#endif // !_BLOCK_
