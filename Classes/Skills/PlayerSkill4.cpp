#include "PlayerSkill4.h"

bool PlayerSkill4::init()
{
    return true;
}

PlayerSkill4::PlayerSkill4()
{
    //风
    //auto sprite = Sprite::create("Skill/17/1.png");
    //龙
    auto sprite = Sprite::create("Skill/1/1.png");
    sprite->setScaleX(0.3);
    sprite->setScaleY(0.3);
    //sprite->setPosition(Vec2(-300,0));
    //auto sprite = Sprite::create("Player/player1/32.png");

    this->bindSprite(sprite);
}

Animate* PlayerSkill4::SkillRun()
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
    animation->setDelayPerUnit(0.05f);
    animation->setRestoreOriginalFrame(true);
    Animate* action = Animate::create(animation);
    return action;
}

void PlayerSkill4::SkillMove(double posX , double posY , bool rotation)
{
    this->stopAllActions();
    this->setPosition(0,0);
    if (this->skillRotation != rotation)
    {
        this->skillRotation = !this->skillRotation;
        if (rotation)
            this->getSprite()->setFlipX(false);
        else
            this->getSprite()->setFlipX(true);
    } 
    auto moveTo = MoveTo::create(2,Vec2(posX,posY));
    auto callbackRotate = CallFunc::create([&](){
        this->setVisible(false);
    });
    auto seq = Sequence::create(moveTo,callbackRotate,NULL);
    this->runAction(seq);
    this->getSprite()->runAction(this->SkillRun());
}