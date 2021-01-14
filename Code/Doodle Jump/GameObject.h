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
protected:
	// -- Position and Size
	Point point;
	int width;
	int height;
	// -- Additional
	GameObjectTypes type;
	int imageID;
	bool isTrigger;
public:
	// Methods
private:
protected:
public:
	GameObject();
	bool	GetIntersections(Point _points[], int _widths[], int _heights[], int _count);
	Point	GetPosition();
	void	SetPosition(Point _point);
	int		GetImageID();
	void	Move(int _xDirection, int _yDirection);
	int		GetWidth();
	int		GetHeight();
};


#endif // !_GAME_OBJECT_

