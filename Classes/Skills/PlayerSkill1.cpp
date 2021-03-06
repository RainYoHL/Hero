#include "PlayerSkill1.h"

bool PlayerSkill1::init()
{
    return true;
}

PlayerSkill1::PlayerSkill1()
{
    //风
    //auto sprite = Sprite::create("Skill/17/1.png");
    //龙
    auto sprite = Sprite::create("Skill/3/1.png");
    sprite->setScaleX(0.3);
    sprite->setScaleY(0.3);
    //sprite->setPosition(Vec2(-300,0));
    //auto sprite = Sprite::create("Player/player1/32.png");

    this->bindSprite(sprite);
}

Animate* PlayerSkill1::SkillRun()
{
    int iFrameNum = 14;
    SpriteFrame* frame;
    Vector<SpriteFrame*> frameVec;
    for (int i = 1 ; i <= iFrameNum ; i++)
    {
        frame = SpriteFrame::create(StringUtils::format("Skill/3/%d.png",i),Rect(0,0,800,1400));
        frameVec.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(1);
    animation->setDelayPerUnit(0.15f);
    animation->setRestoreOriginalFrame(true);
    Animate* action = Animate::create(animation);
    return action;
}

void PlayerSkill1::SkillMove(double posX , double posY , bool rotation)
{
    this->stopAllActions();
    this->setPosition(posX,posY);
    int pos;
    if (rotation == 1)
        pos = 300;
    else
        pos = -300;
    auto moveTo = MoveTo::create(2,Vec2(posX+pos,posY));
    auto callbackRotate = CallFunc::create([&](){
        this->setVisible(false);
    });
    //this->runAction(moveTo);
    auto seq = Sequence::create(moveTo,callbackRotate,NULL);
    this->runAction(seq);
    this->getSprite()->runAction(this->SkillRun());
}