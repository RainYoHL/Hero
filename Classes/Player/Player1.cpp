#include "Player1.h"

Player1::Player1()
{
    bloodScaleX = 0.8;
    auto sprite = Sprite::create("Player/player2/22.png");
    this->bindSprite(sprite);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

  //显示玩家生命值
  // auto blood = Sprite::create("血条.png");
  // blood->setScale(bloodScaleX);
  //  blood->setPosition(Vec2(visibleSize.width/35+origin.x,visibleSize.height/4+origin.y));
  //  this->addChild(blood);
  //  blood->setTag(1);
}
bool Player1::init()
{
    this->playerSkill1 = PlayerSkill1::create();
    this->playerSkill1->setVisible(false);
    this->playerSkill1->setAnchorPoint(Vec2(0.5,0.5));

    this->playerSkill4 = PlayerSkill4::create();
    this->playerSkill4->setVisible(false);
    this->playerSkill4->setAnchorPoint(Vec2(0.5,0.45));
    //log("%.2f %.2f",this->playerSkill4->getPositionX(),this->playerSkill4->getPositionY());
    this->addChild(playerSkill1,20);
    this->addChild(playerSkill4,20);
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

   // auto blood = getChildByTag(1);
   //bloodScaleX -= 0.1;
   // blood->setScaleX(bloodScaleX);

}
void Player1::playerAttack(double posX , double posY , bool rotation)
{

}
void Player1::playerSkill(double posX , double posY , bool rotation , int choiceSkill)
{
    auto Point = convertToNodeSpace(Vec2(posX,posY));
    switch(choiceSkill)
    {
        case 1:
            this->playerSkill1->setVisible(true);
            playerSkill1->SkillMove(Point.x+45,Point.y-40,playerRotation);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            this->playerSkill4->setVisible(true);
            playerSkill4->SkillMove(450,-142,1);
            break;
    }
}

Animate* Player1::playerRun()
{
    int iFrameNum = 4;
    SpriteFrame* frame;
    Vector<SpriteFrame*> frameVec;
    for (int i = 1 ; i <= iFrameNum ; i++)
    {
        frame = SpriteFrame::create(StringUtils::format("Player/player2/%d.png",i+28),Rect(0,0,60,65));
        frameVec.pushBack(frame);
    }
    Animation* animation = Animation::createWithSpriteFrames(frameVec);
    animation->setLoops(2);
    animation->setDelayPerUnit(0.25f);
    animation->setRestoreOriginalFrame(true);
    Animate* action = Animate::create(animation);
    return action;
}