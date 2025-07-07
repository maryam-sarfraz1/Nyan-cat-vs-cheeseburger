#include "Cheeseburger.h"
#include"game.h"
#include <iostream>
#include<fstream>
#include<stdexcept>
#include<string>
#include<thread>
#include<chrono>
using namespace std;
Cheeseburger::Cheeseburger(Grid& g) : GameObject(9, 0, 1, 1, 'C'), grid(g), score(0), immunityMoves(0) {
    lives = 5;
    grid.updateCheeseburgerPosition(x, y);
   
}

void Cheeseburger::move(char direction) {
    int gridWidth = grid.getWidth();
    int gridHeight = grid.getHeight();

    if ((direction == 'L' || direction == 'l') && y > 0) {
        y--; // Move left
    }
    else if ((direction == 'R' || direction == 'r') && y < gridWidth - 1) {
        y++; // Move right
    }
    else if ((direction == 'U' || direction == 'u') && x > 0) {
        x--; // Move up
    }
    else if ((direction == 'D' || direction == 'd') && x < gridHeight - 1) {
        x++; // Move down
    }

    score++;
    collide();
    //immunity chcks
    if (immunityMoves > 0) {
        immunityMoves--;
        if (immunityMoves == 0) {
            cout << "Shield immunity expired!" << endl;
        }
    }

    grid.updateCheeseburgerPosition(x, y);// chnge the position to next position which user enter
    displaylives();
}


void Cheeseburger::draw() {
    cout << "C"; // Symbol for Cheeseburger
}

int Cheeseburger::displaylives() const {
    cout << "Lives: " << lives << endl;
    return lives;
}

void Cheeseburger::collide() {//function handles colision with different characters
    if (immunityMoves > 0) {
        // Skip collisions if immunity is active
       cout << "Immune to collision! Shield protection active." << endl;
       this_thread::sleep_for(chrono::seconds(1));
        return;
    }

    char cell = grid.getCell(x, y);

    if (cell == '@') {
        cout << "Ohh!! Collided with Nyan Cat!" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        lives--;
        reset(this);
    }
    else if (cell == ')') {
        cout << "Collided with Shield! You are immune for the next 3 moves!" <<endl;
        this_thread::sleep_for(chrono::seconds(1));
        immunityMoves = 3;
    }
    else if (cell == '#') {
        cout << "Collided with Friend!" << endl;
        this_thread::sleep_for(chrono::seconds(1));

        if (lives < 5) {
            cout << "Yayyyy!!! You got a life!" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            lives++;
        }
        else {
            cout << "You already have full lives." << endl;
            this_thread::sleep_for(chrono::seconds(1));

        }
    }
    else if (cell == '$') {
        cout << "Ohho!! Collided with Cactus!" << endl;// score and lives --
        //system("pause");
        this_thread::sleep_for(chrono::seconds(1));

        score--;
        lives--;
    }
    else if (cell == '+') {
        cout << "Wow! you collided with a score booster!" << endl;
       // system("pause");
        this_thread::sleep_for(chrono::seconds(1));

        score += 10;

    }
    else {
        cout << "No collision." << endl;
        this_thread::sleep_for(chrono::seconds(1));

    }
   
}

int Cheeseburger::getscore() {
    return score;
}

void Cheeseburger::activatePowerUp() {
    cout << "PowerUp activated!" << endl;

}
// reset function that take burger ti position that it starts from, score is equal to zero
void reset(Cheeseburger* cheeseburger) {
    cheeseburger->x = 9;
    cheeseburger->y = 0;
    cheeseburger->score = 0;
    //cheeseburger->lives = 3;
   cout << "Game reset!" << endl;
}

void displayscore (Cheeseburger* cheeseburger) {
   
  
    try {
        // check if the cheeseburger object is valid
        if (!cheeseburger) {
            throw runtime_error("cheeseburger object is null! no scores available.");
        }
        else {
            cout << "score: " << cheeseburger->score << endl;
        }
        // open file in append mode to save the score
        ofstream outfile("score.txt", ios::app);
        if (!outfile.is_open()) {
            throw runtime_error("error opening scores file for writing!");
        }

        // calculate level and get the current score
        int currentlevel = cheeseburger->getx() / 10 + 1; // adjust this logic as needed
        int currentscore = cheeseburger->getscore();

        // write the score to the file
        outfile << "level: " << currentlevel << " | score: " << currentscore << endl;
        outfile.close();

        // open file in read mode to display previous scores
        ifstream infile("score.txt");
        if (!infile.is_open()) {
            throw runtime_error("error opening scores file for reading!");
        }

        cout << "previous scores:" << endl;
        string line;
        while (getline(infile, line)) { // read scores line by line
            cout << line << endl;
        }
        infile.close();
    }
    catch (const runtime_error& e) {
        // handle runtime errors
        cout << "exception: " << e.what() << endl;
    }
    catch (...) {
        // handle any other exceptions
        cout << "an unknown error occurred while displaying scores." << endl;
    }


}