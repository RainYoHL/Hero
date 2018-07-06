#include "Player1.h"

Player1::Player1()
{
    bloodScaleX = 0.8;
    auto sprite = Sprite::create("Player/player1/32.png");
    this->bindSprite(sprite);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto blood = Sprite::create("血条.png");
    blood->setScale(bloodScaleX);
    blood->setPosition(Vec2(visibleSize.width/35+origin.x,visibleSize.height/4+origin.y));
    this->addChild(blood);

    blood->setTag(1);
}
bool Player1::init()
{
    this->playerSkill1 = PlayerSkill1::create();
    this->playerSkill1->setVisible(false);
    this->playerSkill1->setAnchorPoint(Vec2(0.5,0.45));
    //log("%.2f %.2f",this->playerSkill1->getPositionX(),this->playerSkill1->getPositionY());
    this->addChild(playerSkill1,20);
    return true;
}

void Player1::playerMove(double posX , double posY , bool rotation)
{
    //rotation 真 反转 假 不变
    this->stopAllActions();
    if (this->playerRotation != rotation)
    {
        this->playerRotation = !this->playerRotation;
        if (rotation)
            this->getSprite()->setFlipX(false);
        else
            this->getSprite()->setFlipX(true);
    }
    auto moveTo = MoveTo::create(2,Vec2(posX,posY));
    this->runAction(moveTo);
    this->getSprite()->runAction(this->playerRun());

    auto blood = getChildByTag(1);
    bloodScaleX -= 0.1;
    blood->setScaleX(bloodScaleX);


}
void Player1::playerAttack(double posX , double posY , bool rotation)
{

}
void Player1::playerSkill(double posX , double posY , bool rotation)
{
    //playerSkill1->setPosition(0,0);
    //log("%.2f %.2f",posX,posY-2*this->getPositionY());
    this->playerSkill1->setVisible(true);
    playerSkill1->SkillMove(450,-142,1);
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