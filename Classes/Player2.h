#ifndef _PLAYER2_H
#define _PLAYER2_H

#include "cocos2d.h"
#include "Player.h"

class Player2 : public Player
{
public:
    virtual void playerMove();
    virtual void playerAttack();
    virtual void playerSkill();
};

#endif