#include "NyanCat.h"
#include<iostream>
#include"game.h"
using namespace std;

NyanCat::NyanCat(int x, int y) : GameObject(x, y, 1, 1, '@') {}

void NyanCat::draw(char** grid, int height, int width) {
    if (x >= 0 && x < height && y >= 0 && y < width) { // Ensure valid grid boundaries
        grid[x][y] = symbol; // Place the NyanCat in the grid
        
    }
}

void NyanCat::fall(char** grid, int height, int width) {
    if (x >= 0 && x < height && y >= 0 && y < width) {
        grid[x][y] = '.'; // Clear current position
        x += 2;           // Move down by 2 rows

        if (x >= height) { // If it falls off the grid, reset to top
            x = 0;
        }
        grid[x][y] = symbol; // Update new position
    }
}

void NyanCat::move(char direction) {
    cout << "move done" << endl;
}

void NyanCat::collide() {
    cout << "collision done" << endl;
}
