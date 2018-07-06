#ifndef _PLAYER1_H
#define _PLAYER1_H

#include "cocos2d.h"
#include "Player.h"
#include "Skills/PlayerSkill1.h"
#include "Skills/Skill.h"
USING_NS_CC;

class Player1 : public Player
{
public:
    CREATE_FUNC(Player1);
    Player1();
    virtual bool init();
    virtual void playerMove(double posX , double posY , bool rotation);
    virtual void playerAttack(double posX , double posY , bool rotation);
    virtual void playerSkill(double posX , double posY , bool rotation);
    virtual Animate* playerRun();
private:
    Skill* playerSkill1;
    float bloodScaleX;
};

#endif