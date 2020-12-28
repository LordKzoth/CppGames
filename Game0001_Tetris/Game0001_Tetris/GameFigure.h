//===================================
// Include guard
#ifndef _GAME_FIGURE_
#define _GAME_FIGURE_

//===================================
// Figure

class GameFigure {
	// Fields
public:
protected:
private:
	int		colorNum;
	// Methods
public:
	GameFigure();
	void CreateNewFigure();
	void MoveFigure(int _dx);
	void RotateFigure(bool rotate);
	//SET-GET
	int GetColorNum() { return colorNum; }
protected:
private:
};

#endif // !_GAME_FIGURE_
