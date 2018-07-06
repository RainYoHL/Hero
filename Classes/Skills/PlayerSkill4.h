#ifndef _PlayerSkill4_H
#define _PlayerSkill4_H

#include "cocos2d.h"
#include "Skill.h"

USING_NS_CC;

class PlayerSkill4 : public Skill
{
public:
    PlayerSkill4();
    virtual bool init();
    virtual void SkillMove(double posX , double posY , bool rotation);
    virtual Animate* SkillRun();
    CREATE_FUNC(PlayerSkill4);
};

#endif