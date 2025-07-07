#include "Grid.h"
#include"Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
#include<Windows.h>
using namespace std;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   
Grid::Grid(int h, int w) : height(h), width(w), cheeseburgerX(0), cheeseburgerY(0) {
    // Allocate dynamic grid
    grid = new char* [height];
    for (int i = 0; i < height; i++) {
       
       grid[i] = new char[width];
        for (int j = 0; j < width; j++) {
           
          grid[i][j] = '.'; // Initialize with dots
        }
        cout << endl;
    }
    grid[cheeseburgerX][cheeseburgerY] = 'C'; // Place Cheeseburger
}

Grid::~Grid() {
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Grid::displayGrid() {
    cout << endl << endl << endl;
    for (int i = 0; i < height; i++) {
        cout << "\t\t\t\t\t\t";
        for (int j = 0; j < width; j++) {
            char cell = grid[i][j];
            // Set colors based on the cell's content
            switch (cell) {
            case '.':
                SetConsoleTextAttribute(hConsole, 7); //  empty cells
                break;
            case 'C':
                SetConsoleTextAttribute(hConsole, 14);//  Cheeseburger
                break;
            case '@':
                SetConsoleTextAttribute(hConsole, 4); //  Nyan Cat
                break;
            case '#':
                SetConsoleTextAttribute(hConsole, 11); // Friends
                break;
            case ')':
                SetConsoleTextAttribute(hConsole, 9); // Shield PowerUp
                break;
            case '$':
                SetConsoleTextAttribute(hConsole,10 );// Cactus
                break;
            case '+':
                SetConsoleTextAttribute(hConsole, 13); // Booster PowerUp
                break;
            default:
                SetConsoleTextAttribute(hConsole, 7); // Default to white
                break;
            }
            cout << cell << " ";
        }
        cout << endl;
    }
    // Reset to default color after drawing
     SetConsoleTextAttribute(hConsole, 7);
    cout << endl;
}

void Grid::placeRandomObjects(int numPowerUps, int numFriends, int numNyanCats) {
    srand(static_cast<unsigned int>(time(0))); // Fix warning about data type conversion

    for (int i = 0; i < numPowerUps; i++) {// for generating powerups
        int x = rand() % height;
        int y = rand() % width;

        char symbol;
        string type;

        if (i < 3) {
            symbol = ')';
           
            type = "Shield";
        }
        else if (i < 6) {
            symbol = '$';
            type = "Cactus";
        }
        else {
            symbol = '+';
            type = "Booster";
        }

        PowerUp powerUp(x, y, symbol, type);// constructor calls
        powerUp.draw(grid, height, width);//function calls
    }

    // Place Friends
    for (int i = 0; i < numFriends; i++) {
        int x = rand() % height;
        int y = rand() % width;
        Friend friendObj(x, y);
        friendObj.draw(grid, height, width);
    }

    // Place Nyan Cats
    for (int i = 0; i < numNyanCats; i++) {
        int y = rand() % width;
        NyanCat nyanCat(0, y);
       // SetColor(13);
        nyanCat.draw(grid, height, width);
    }
}


void Grid::moveNyanCats(int level) {
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j] == '@') { // Found a Nyan Cat
                grid[i][j] = '.';   // Clear its current position

                int newX = i + level;  // Move down 2 positions
                if (newX >= height) {
                    newX = 0;      // Wrap around to the top if it goes out of bounds
                }

                grid[newX][j] = '@'; // Update new position
            }
        }
    }
}


void Grid::updateCheeseburgerPosition(int x, int y) {
    // Clear previous position if valid
    if (cheeseburgerX >= 0 && cheeseburgerX < height && cheeseburgerY >= 0 && cheeseburgerY < width) {
        grid[cheeseburgerX][cheeseburgerY] = '.';
    }
    cheeseburgerX = x;
    cheeseburgerY = y;
    grid[cheeseburgerX][cheeseburgerY] = 'C';
    
}
// function for getting cell  

char Grid::getCell(int x, int y) const {
    if (x >= 0 && x < height && y >= 0 && y < width) {
        return grid[x][y];
    }
    else {
        cout << "Invalid cell access: Out of bounds." << endl;
        return'.';
    }
}

int Grid::getWidth() const { return width; }// for getting width
int Grid::getHeight() const { return height; }// for getting height
