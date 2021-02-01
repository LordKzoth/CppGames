//==============================
// Include dependencies
// -- Libraries
#include <SFML/Graphics.hpp>
#include <fstream>

// -- Headers
#include "GameEngine.h"

// -- Namespaces
using namespace sf;

//==============================
// Additional
void    SaveTotalScoreToFile(int);
int     LoadTotalScoreFromFile();

// Main part
int main() {
#ifndef _DEBUG
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
#endif

    srand(time(0));
    Clock clock;

    RenderWindow window(VideoMode(512, 512), "Arcanoid");

    View mainCamera;
    mainCamera.setCenter(0, 0);
    mainCamera.setSize(512, 512);

    window.setView(mainCamera);

    int currentLevel = 0;
    int totalScore = 0;
    int bestScore = LoadTotalScoreFromFile();
    while (window.isOpen()) {
        GameEngine* gameEngine = new GameEngine(currentLevel, totalScore, bestScore);
        gameEngine->window = &window;
        gameEngine->mainCamera = &mainCamera;

        while (window.isOpen() && !gameEngine->CheckGameStatus()) {
            gameEngine->deltaTime = clock.restart().asSeconds();

            gameEngine->Update();
            gameEngine->Draw();
        }

        if (gameEngine->countOfBlocks == 0) {
            currentLevel++;
            totalScore = gameEngine->totalScore;
            if (totalScore > bestScore) {
                bestScore = totalScore;
                SaveTotalScoreToFile(bestScore);
            }
            if (currentLevel == 3) currentLevel = 0;
        }

        delete gameEngine;
    }
    return 0;
}

void SaveTotalScoreToFile(int _totalScore) {
    std::ofstream os;
    os.open("Best Score.txt", std::ios::out);

    os << _totalScore;

    os.close();
}

int LoadTotalScoreFromFile() {
    int result = 0;

    std::ifstream is;

    is.open("Best Score.txt", std::ios::in);
    if (is) {
        is >> result;
    }
    is.close();

    return result;
}