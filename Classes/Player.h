#ifndef _PLAYER_H
#define _PLAYER_H

#include "cocos2d.h"
#include "Entity.h"

class Player : public Entity
{
public:
    Player();
    ~Player();
    virtual void playerMove(double posX , double posY , bool rotation) = 0;
    virtual void playerAttack(double posX , double posY , bool rotation) = 0;
    virtual void playerSkill(double posX , double posY , bool rotation , int choiceSkill) = 0;
    virtual Animate* playerRun() = 0;

protected:
    int playerHP;
    int playerMP;
    int skillCD;
    int playerRotation;
    bool isSkilling;
};

#endif