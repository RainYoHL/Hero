#include "PlayerSkill1.h"

bool PlayerSkill1::init()
{
    return true;
}

PlayerSkill1::PlayerSkill1()
{
    auto sprite = Sprite::create("Skill/1/1.png");
    this->bindSprite(sprite);
}

Animate* PlayerSkill1::SkillRun()
{
    int iFrameNum = 38;
    SpriteFrame* frame;
    Vector<SpriteFrame*> frameVec;
    for (int i = 1 ; i <= iFrameNum ; i++)
    {
        frame = SpriteFrame::create(StringUtils::format("Skill/1/%d.png",i),Rect(0,0,5800,2000));
        frameVec.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(1);
    animation->setDelayPerUnit(0.35f);
    animation->setRestoreOriginalFrame(true);
    Animate* action = Animate::create(animation);
    return action;
}

void PlayerSkill1::SkillMove(double posX , double posY , bool rotation)
{
    log("test");
}