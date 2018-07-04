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
    virtual void playerMove();
    virtual void playerAttack();
    virtual void playerSkill();
private:
    cocos2d::Animate* createAnimate();
};

#endif