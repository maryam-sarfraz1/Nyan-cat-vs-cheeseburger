#ifndef CHEESEBURGER_H
#define CHEESEBURGER_H

#include "GameObject.h"
#include "Grid.h"

class Cheeseburger : public GameObject {
private:
    int score;
    int lives;
    int immunityMoves; // Counter for shield-based immunity
    Grid& grid;

public:
    Cheeseburger(Grid& g);
    void move(char direction) override;
    void draw() ;
    int displaylives() const;
    void collide() override;
    int getscore();
    void activatePowerUp();
   friend void reset(Cheeseburger* cheeseburger);
  friend void displayscore(Cheeseburger* cheeseburger);
  int getx() { return x;}
  
 // void displayscore() ;
  

};
//void reset(Cheeseburger* cheeseburger){}
 //void displayscore(Cheeseburger* cheeseburger){}

#endif // CHEESEBURGER_H

