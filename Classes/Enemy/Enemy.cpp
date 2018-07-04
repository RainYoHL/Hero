#include "Enemy.h"

Wolf::Wolf()
{
    auto sprite = Sprite::create("enemy1/0.png");
    this->bindSprite(sprite);
    this->playerMove();
}
bool Wolf::init()
{
    return true;
}
void Wolf::playerMove()
{
    auto moveby = MoveBy::create(2,Vec2(50,0));
    auto move = Spawn::createWithTwoActions(moveby,this->createAnimate());
    this->getSprite()->runAction(move);
}

void Wolf::playerAttack()
{

}

void Wolf::playerSkill()
{

}

cocos2d::Animate* Wolf::createAnimate()
{
    int iFrameNum = 4;
    SpriteFrame* frame = NULL;
    Vector<SpriteFrame*> frameVec;

    for(int i = 0;i < iFrameNum; i++)
    {
        frame = SpriteFrame::create(StringUtils::format("enemy1/%d.png",i),Rect(0,0,120,80));
        frameVec.pushBack(frame);
    }

    Animation* animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    Animate* action = Animate::create(animation);

    return action;
}
