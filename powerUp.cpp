#include "PowerUp.h"
#include <iostream>
using namespace std;
PowerUp::PowerUp(int x, int y, char sym, const std::string& typ)
    : GameObject(x, y, 1, 1, sym), type(typ), duration(5), isActive(false) {}

void PowerUp::draw(char** grid, int height, int width) {
    if (x >= 0 && x < height && y >= 0 && y < width) { // Ensure valid grid boundaries
        grid[x][y] = symbol; // Place the PowerUp on the grid
    }
}

void PowerUp::activating() {
    isActive = true;
    cout << "PowerUp activated for " << duration << " turns!" <<endl;
}

void PowerUp::deactivating() {
    isActive = false;
    cout << "PowerUp deactivated." <<endl;
}
void PowerUp::move(char direction) {
    cout << "move done" << endl;
    return;
}
void PowerUp::collide() {
    cout << "collision done" << endl;
    return;
}


