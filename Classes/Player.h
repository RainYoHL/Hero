#ifndef _PLAYER_H
#define _PLAYER_H

#include "cocos2d.h"

class Player : public Entity
{
public
    Player();
    ~Player();
    virtual void playerMove();
    virtual void playerAttack();
    virtual void playerSkill();
private:
    int playerHP;
    int playerMP;
    int skillCD;
};

#endif