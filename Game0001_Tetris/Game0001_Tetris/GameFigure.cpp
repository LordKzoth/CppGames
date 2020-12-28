//=======================
// Include dependencies
#include "GameFigure.h"
#include "GameData.h"

//=======================
// Definition of Class Methods
GameFigure::GameFigure() {
	colorNum = 0;
}

void GameFigure::CreateNewFigure() {
	for (int i = 0; i < 4; i++) {
		map[b[i].y][b[i].x] = colorNum;
	}

	colorNum = 1 + rand() % 7;
	int n = colorNum - 1;
	for (int i = 0; i < 4; i++) {
		a[i].x = figures[n][i] % 2;
		a[i].y = (figures[n][i] / 2) - 1;
	}
}

void GameFigure::MoveFigure(int dx) {
	for (int i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += dx;
	}
	if (!Check()) {
		for (int i = 0; i < 4; i++) {
			a[i] = b[i];
		}
	}
}

void GameFigure::RotateFigure(bool rotate) {
	if (rotate) {
		Point figureCenter = a[1];
		for (int i = 0; i < 4; i++) {
			int x = a[i].y - figureCenter.y;
			int y = a[i].x - figureCenter.x;
			a[i].x = figureCenter.x - x;
			a[i].y = figureCenter.y - y;
		}

		if (!Check()) {
			for (int i = 0; i < 4; i++) {
				a[i] = b[i];
			}
		}
	}
}