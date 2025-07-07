#include "game.h"
#include <iostream>
#include<iomanip>
#include <cstdlib>
#include<ctime>
#include<thread>
#include<windows.h>
#include<chrono>
#include<string>
using namespace std;

void Game::SetColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

Game::Game() : over(false), move1(0), input(0), level(1), cheeseburger(nullptr) {}//constructor

Game::~Game() {//destructor 
    if (cheeseburger != nullptr) {
        delete cheeseburger;
        cheeseburger = nullptr;
    }
}

void Game::displayNyanCat() {
    system("cls");
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
    }
    SetColor(12);
    cout << setw(60) << " " << "/\\_/\\\n";
    cout << setw(59) << " " << "( ^.^ )\n";
    cout << setw(59) << " " << " > ^ <\n";
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    cout << setw(45) << " " << "Nyan Cat is ready for an adventure!" << endl;
        cout << setw(55) << " " << "Yayyyyyy!!!!!" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << endl;
        }
        SetColor(8);
        this_thread::sleep_for(chrono::seconds(2));
       
}
void Game::mainMenu() {
    string playername;
    system("cls");
    SetColor(11);

    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
    cout << setw(80) << "=======================================" << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << setw(47) << " " << "NYAN CAT VS CHEESEBURGER\n";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << setw(80) << "=======================================" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << endl;
    }
    SetColor(8);
    this_thread::sleep_for(chrono::seconds(2));
 
    displayNyanCat();
    system("cls");
    for (int i = 0; i < 15; i++)
    {
        cout << endl;
    }
    SetColor(14);

    cout << setw(55) << " " << "Loading Game";
    for (int i = 0; i < 5; i++) {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(500)); // Simulate loading
    }

    system("cls");
    for (int i = 0; i < 15; i++)
    {
        cout << endl;
    }
    SetColor(5);
    cout << setw(45) << " " << "Game is ready to start!\n";
   
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
    SetColor(11);
    cout << endl << setw(50) << setfill(' ') << "Enter your name: ";
    getline(cin, playername);
    cout << endl << setw(50) << setfill(' ') << "Hello, " << playername << "!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << endl;

    system("cls");
   
    while (true) {
        system("cls");
        cout << "\n\n";
        for (int i = 0; i < 8; i++)
        {
            cout << endl;
        }
        SetColor(11);
        cout << setw(70) << "=======================" << endl;
        cout << endl;
        cout << endl;
        cout << setw(55) << " " << "MAIN MENU\n";
        cout << endl;
        cout << endl;
        cout << setw(70) << "=======================" << endl;
        cout << endl;
        cout << setw(40) << " " << "1. Start Game\n";
        cout << setw(40) << " " << "2. Instructions\n";
        cout << setw(40) << " " << "3. Quit\n";
        cout << setw(40) << " " << "4. Credits\n";
         cout << setw(40) << " " << "Enter your choice: ";

        int choice;
        cin >> choice;
        switch (choice) {
                    case 1:
                        SetColor(15);
                        startGame(10, 2, 3, 10, 10);//game started
                        break;
                    case 2://show instructions
                        system("cls");
                        SetColor(11);
                        for (int i = 0; i < 10; i++)
                        {
                            cout << endl;
                        }
                        cout << setw(75) << "=======================" << endl;
                        cout << setw(53) << " " << "INSTRUCTIONS\n";
                        cout << setw(75) << "=======================" << endl;cout << endl;
                        cout << setw(45) << " " << "1. Use U, D, L, R to move Cheeseburger ('C').\n";
                        cout << setw(45) << " " << "2. Avoid Nyan Cats ('@').\n";
                        cout << setw(45) << " " << "3. Collect items like friend ('#') for points.\n";
                        cout << setw(45) << " " << "4. Collect shield(')') for protection from nyan cat.\n";
                        cout << setw(45) << " " << "5. Try to avoid to collide with cactus('$').\n";
                        cout << setw(45) << " " << "6. Levels get progressively harder.\n";
                        cout << setw(45) << " " << "Press Enter to return to the menu...";
                        cin.ignore();
                        cin.get();
                        break;
                    case 3:
                        system("cls");
                        SetColor(11);
                        gameOver();
                       cout << setw(20) << " " << "Exiting the game. Goodbye!\n";
                       cout << endl;
                       exit(0);
                        break;
                    case 4:
                        system("cls");
                        SetColor(11);
                        for (int i = 0; i < 15; i++)
                        {
                            cout << endl;
                        }
                        cout << setw(70) << "======================" << endl;
                        cout << setw(58) << "CREDITS" << endl;
                        cout << setw(70) << "======================" << endl;cout << endl;
                        cout << setw(45) << " " << "Developers:\n";
                        cout << setw(45) << " " << "Bushra Batool & Maryam Sarfraz\n";cout << endl;
                        cout << setw(45) << " " << "Press Enter to return to the menu...";
                        cin.ignore();
                        cin.get();
                        break;
                    default:
                        SetColor(13);
                        cout << setw(10) << " " << "Invalid choice! Please try again.\n";
                        mainMenu();
                        break;
        }
    }
}

    void Game::startGame(int p, int q, int r, int gridHeight, int gridWidth) {
        system("cls");
        Grid grid(gridHeight, gridWidth);

        // Initialize the cheeseburger object dynamically
        if (cheeseburger != nullptr) {
            delete cheeseburger;
        }
        cheeseburger = new Cheeseburger(grid);

        // Place random objects
        grid.placeRandomObjects(p, q, r);

        // Define score thresholds for each level
        const int totalLevels = 3; // Total number of levels
        int levelThresholds[totalLevels] = {20,25,30 };

        char command;
        cout << "Move Cheeseburger (U: Up, D: Down, L: Left, R: Right, Q for Quit, P for Pause):" << endl;

        do {
            system("cls");
           

            grid.displayGrid();
            cout << setw(10) << " " << "Lives: " << cheeseburger->displaylives() << "  |  Score: " << cheeseburger->getscore() << "\n";

            cout << "Enter command: ";
            cin >> command;

            if (command == 'Q'|| command =='q') break;

            if (command == 'P'||command =='p') {
                
                pause();
                continue;
            }

            cheeseburger->move(command);    // Use the cheeseburger member variable
            grid.moveNyanCats(level);       // Move Nyan Cats down
            move1++;

            // Display score
            cout << "Your score is: " << cheeseburger->getscore() << endl;

            // Check for game over conditions
            if (cheeseburger->displaylives() == 0) {
                SetColor(2);
                cout << "Game Over! You've lost all lives." << endl;
                gameOver();
                return;
            }

            // Check for level completion
            if (cheeseburger->getscore() >= levelThresholds[level - 1]) {
                over = true;
                system("cls");
                for (int i = 0;  i < 10; i++)
                {
                    cout << endl;
                }
                SetColor(11);
                cout <<setw(75)<< "Wow! Completed Level " << level << "!" << endl;
                for (int i = 0; i < 15;i++) {
                    cout << endl;
                }
               system("pause");

                if (level < totalLevels) {
                    level++;
                    update(gridHeight + 2, gridWidth + 2);
                }
                else {
                    cout << "Congratulations! You've completed all levels!" << endl;
                    system("pause");
                    return;
                }
            }

        } while (!over);
    }

void Game::update(int nextGridHeight, int nextGridWidth) {// update game for next levels
    system("cls");
    over = false;
    cout << "Press 1 to go to the next level, or 2 to quit: ";
    cin >> input;

    switch (input) {
    case 1:
        delete cheeseburger;
        cheeseburger = nullptr; // Reset the pointer
        startGame(13, 7, 10, nextGridHeight, nextGridWidth);

        if (cheeseburger) {
            reset(cheeseburger); // Use friend function to reset
        }

        break;

    case 2:
        cout << "Game Ended." << endl;
        over = true; // Set the game over flag
        return;

    default:
        cout << "Invalid input. Please try again." << endl;
        break;
    }
}

void Game::pause() {// for pause
    system("cls");
    SetColor(11);
    for (int i = 0; i < 13; i++)
    {
        cout << endl;
    }
    cout << setw(65) <<  "======================\n";
    cout << setw(58)<<"Game Paused!" << endl;
    cout << setw(65) <<"======================\n";
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
    }
    cout << setw(115)<<"Press any key to resume..." << endl;
    cin.ignore();
    cin.get();
}

void Game::gameOver() {
    for (int i = 0; i < 15; i++)
    {
        cout << endl;
    }
    cout <<setw(65)<<"======================\n";
    cout <<setw(56)<<    "Game over" << endl;
    cout << setw(65)<< "======================\n";
}

