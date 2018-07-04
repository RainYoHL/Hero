#ifndef _PLAYER1_H
#define _PLAYER1_H

#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;

class Player1 : public Player
{
public:
    CREATE_FUNC(Player1);
    Player1();
    virtual bool init();
    virtual void playerMove();
    virtual void playerAttack();
    virtual void playerSkill();
};

#endif