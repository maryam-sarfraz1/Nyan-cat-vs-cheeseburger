#ifndef POWERUP_H
#define POWERUP_H

#include <string>
#include "GameObject.h"

class PowerUp : public GameObject {
private:
    std::string type;          // Type of PowerUp (e.g., "Shield" or "Cactus")
    bool isActive;
    int duration;

public:
    PowerUp(int x, int y, char sym, const std::string& typ);
    void draw(char** grid, int height, int width);
    void move(char direction) override;
    void collide() override;

    void activating();
    void deactivating();
};

#endif // POWERUP_H
