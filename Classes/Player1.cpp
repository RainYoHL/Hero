#include "Player1.h"

Player1::Player1()
{
    auto sprite = Sprite::create("Player/player1/32.png");
    this->bindSprite(sprite);
}
bool Player1::init()
{
    return true;
}

void Player1::playerMove(double posX , double posY , bool rotation)
{
    //rotation 真 反转 假 不变
    if (this->playerRotation != rotation)
    {
        log("开始反转");
        this->playerRotation = !this->playerRotation;
        if (rotation)
            this->getSprite()->setFlipX(false);
        else
            this->getSprite()->setFlipX(true);
    }
    auto moveTo = MoveTo::create(2,Vec2(posX,posY));
    this->runAction(moveTo);
    this->getSprite()->runAction(this->playerRun());
}
void Player1::playerAttack(double posX , double posY)
{

}
void Player1::playerSkill(double posX , double posY)
{

}

Animate* Player1::playerRun()
{
    int iFrameNum = 7;
    SpriteFrame* frame;
    Vector<SpriteFrame*> frameVec;
    for (int i = 1 ; i <= iFrameNum ; i++)
    {
        frame = SpriteFrame::create(StringUtils::format("Player/player1/%d.png",i+5),Rect(0,0,80,65));
        frameVec.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(1);
    animation->setDelayPerUnit(0.35f);
    animation->setRestoreOriginalFrame(true);
    Animate* action = Animate::create(animation);
    return action;
}