#ifndef _PLAYER2_H
#define _PLAYER2_H

#include "cocos2d.h"
#include "Player.h"

class Player2 : public Player
{
public:
    virtual void playerMove(double posX , double posY , int rotation);
    virtual void playerAttack(double posX , double posY);
    virtual void playerSkill(double posX , double posY);
};

#endif