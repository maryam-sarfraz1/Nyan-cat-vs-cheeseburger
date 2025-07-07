#include "friends.h"
#include <iostream>
using namespace std;
Friend::Friend(int x, int y) : GameObject(x, y, 1, 1, '#'), supportLevel(0) {}

void Friend::draw(char** grid, int height, int width) {
    if (x >= 0 && x < height && y >= 0 && y < width) { // Ensure valid grid boundaries
        grid[x][y] = symbol; // Place the Friend on the grid
    }
}

void Friend::collide() {
    cout << "Friend collided with another object!" << endl;
}
void Friend::move(char direction) {
    cout << "move done" << endl;
}
void increaseSupportlevel(Friend* friendd) {
    friendd->supportLevel++;
   cout << "Support level increased to " << friendd->supportLevel << endl;
}