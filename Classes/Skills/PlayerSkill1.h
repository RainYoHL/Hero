#ifndef _PlayerSkill1_H
#define _PlayerSkill1_H

#include "cocos2d.h"
#include "Skill.h"

USING_NS_CC;

class PlayerSkill1 : public Skill
{
public:
    PlayerSkill1();
    virtual bool init();
    virtual void SkillMove(double posX , double posY , bool rotation);
    virtual Animate* SkillRun();
    CREATE_FUNC(PlayerSkill1);
};

#endif