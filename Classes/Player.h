#ifndef _PLAYER_H
#define _PLAYER_H

#include "cocos2d.h"
#include "Entity.h"

class Player : public Entity
{
public:
    Player();
    ~Player();
    virtual void playerMove() = 0;
    virtual void playerAttack() = 0;
    virtual void playerSkill() = 0;
private:
    int playerHP;
    int playerMP;
    int skillCD;
};

#endif