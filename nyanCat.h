#ifndef NYANCAT_H
#define NYANCAT_H

#include "GameObject.h"

class NyanCat : public GameObject {
public:
    NyanCat(int x, int y);
    void draw(char** grid, int height, int width) ;
    void move(char direction) override;       // Abstract method for moving objects
    void collide() override;
    void fall(char** grid, int height, int width);
};

#endif // NYANCAT_H
