//===================================
// Include guard
#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

//===================================
// Include dependencies
#include <string>

//===================================
// GameObject Types
enum class GameObjectTypes {
	Nothing,
	Platform,
	JumpPlatform,
	Player,
	Enemy
};

struct Point {
	int x;
	int y;
};

// Class declaration

class GameObject {
	// Fields
private:
	// -- Position and Size
	Point point;
	int width;
	int height;
	// -- Additional
	GameObjectTypes type;
	int imageID;
	bool isTrigger;
protected:
public:
	// Methods
private:
protected:
public:
	GameObject();
	bool	GetIntersections(Point points[], int widths[], int heights[], int myIndex);
	Point	GetPosition();
	int		GetImageID();

};


#endif // !_GAME_OBJECT_

