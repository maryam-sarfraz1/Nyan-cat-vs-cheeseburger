#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
    int x, y;         // x and y represent the positions
    int width, height; // represent the dimensions
    char color;
    char symbol;

public:
    GameObject(int a, int b, int wid, int hght, char colr, char sym) : x(a), y(b), width(wid), height(hght), color(colr), symbol(sym) {}
    GameObject(int a, int b, int wid, int hght, char sym) : x(a), y(b), width(wid), height(hght), symbol(sym) {
        color = '0';
    }

   // virtual void draw() = 0;       // pure virtual method for rendering objects
    virtual void move(char direction) = 0;       // Abstract method for moving objects
    virtual void collide() = 0; // pure virtual function that handles collision with different objects

    char getSymbol() const { return symbol; }
};

#endif // GAMEOBJECT_H
