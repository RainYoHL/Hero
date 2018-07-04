#ifndef _Skill_H
#define _Skill_H

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Skill : public Entity
{
public:
    Skill();
    ~Skill();
    virtual void SkillMove(double posX , double posY , bool rotation) = 0;
    virtual Animate* SkillRun() = 0;

protected:
    int skillRotation;
};

#endif