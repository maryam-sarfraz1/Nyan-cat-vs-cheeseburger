#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Cheeseburger.h"
class Game {
private:
    Cheeseburger* cheeseburger; // Cheeseburger object
    bool over; // Game over flag
    int move1; // Move counter
    int input; // User input for gameOver
    int level;
 
public:
    Game();
    ~Game();
    void mainMenu();
    void startGame(int p, int q, int r, int gridHeight, int gridWidth);
    void update(int nextGridHeight, int nextGridWidth);
    void pause();
    void gameOver();
    void displayNyanCat();
    static void SetColor(int textColor);
};

#endif // GAME_H
