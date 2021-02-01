//===========================
// Include guard
#ifndef _GAME_OBJECT_
#define _GAME_OBJECT_

//===========================
// Additional data
struct Point {
	int x;
	int y;
};

enum class GameObjectTypes {
	None,
	Player,
	Block,
	Ball,
	Wall,
	Bonus,
	DeathZone
};

// Class declaration
class GameObject {
	// Fields
private:
protected:
	// -- Position
	Point			position;
	// -- Size
	int				width;
	int				height;
	// -- Other game data
	GameObjectTypes type;
public:
	bool			isEnabled;
	// Methods
private:
protected:
public:
	GameObject();

	void	SetPosition(Point _position);
	Point	GetPosition();
	int		GetWidth();
	int		GetHeight();

	void Move(int _xDirection, int _yDirection);
	bool GetIntersections(GameObject _gameObjects[], int _size);
};

#endif // !_GAME_OBJECT_