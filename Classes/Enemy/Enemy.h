#ifndef _ENEMY_H
#define _ENEMY_H
#include "cocos2d.h"
#include "Player.h"
USING_NS_CC;

class Wolf : public Player
{
public:
    CREATE_FUNC(Wolf);
    Wolf();
    virtual bool init();
    virtual void playerMove(double posX,double posY,bool rotation);
    virtual void playerAttack(double posX,double posY);
    virtual void playerSkill(double posX,double posY);

    virtual Animate* playerRun();
};

#endif