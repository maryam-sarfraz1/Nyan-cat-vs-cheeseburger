#ifndef FRIEND_H
#define FRIEND_H

#include "GameObject.h"

class Friend : public GameObject {
private:
    int supportLevel;

public:
    Friend(int x, int y);
    void draw(char** grid, int height, int width) ;
  friend void increaseSupportlevel(Friend* friendd);
    void collide() override;
    void move(char direction);
};
//void increaseSupportlevel(Friend* friendd){}
#endif // FRIEND_H
