#ifndef GRID_H
#define GRID_H

#include "powerUp.h"
#include "friends.h"
#include "nyanCat.h"

class Grid {
private:
    int height, width;
    int cheeseburgerX, cheeseburgerY;
    char** grid;

public:
    Grid(int h, int w);
    ~Grid();
    void displayGrid();
    void placeRandomObjects(int numPowerUps, int numFriends, int numNyanCats);
    void updateCheeseburgerPosition(int x, int y);
    char getCell(int x, int y) const;
    void moveNyanCats(int level); // Moves Nyan Cats down after each player move
    int getWidth() const;
    int getHeight() const;
    // Add this function declaration to the Grid class
   // void SetColor(int colorCode);

};

#endif // GRID_H
