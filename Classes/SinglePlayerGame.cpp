#include "SinglePlayerGame.h"
#include "Player.h"
#include "Player/Player1.h"
#include "Enemy/Enemy.h"
USING_NS_CC;

Scene* SinglePlayerGame::createScene()
{
    return SinglePlayerGame::create();
}

bool SinglePlayerGame::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto background_image = Sprite::create("Map/Map1/image3.png");
    background_image->setPosition(Vec2(visibleSize.width/2+origin.x,
                                       visibleSize.height/2+origin.y));
    auto background_image1 = Sprite::create("Map/Map1/image4.png");
    background_image->setPosition(Vec2(visibleSize.width/2+origin.x,
                                       visibleSize.height/2+origin.y));
    //适配屏幕分辨率
    //background_image->setScaleX(visibleSize.width/background_image->getTextureRect().getMaxX());
	background_image->setScaleY(visibleSize.height/background_image->getTextureRect().getMaxY());
	background_image1->setScaleY(visibleSize.height/background_image1->getTextureRect().getMaxY());
    this->addChild(background_image,8);
    //this->addChild(background_image1,10);

    //创建技能
    //技能4 龙
    MenuItemImage* skill4 = MenuItemImage::create(
        "Skill/1/10017.png",
        "Skill/1/10019.png",
        CC_CALLBACK_0(SinglePlayerGame::playerSkill4,this));

    skill4->setScaleY(0.05);
    skill4->setScaleX(0.015);

    //技能3
    //火
    MenuItemImage* skill3 = MenuItemImage::create(
        "Skill/8/sprite 380004.png",
        "Skill/8/sprite 380005.png",
        CC_CALLBACK_0(SinglePlayerGame::playerSkill3,this));

    skill3->setScale(0.18);

    //技能2
    //风
    MenuItemImage* skill2 = MenuItemImage::create(
        "Skill/17/sprite 630002.png",
        "Skill/17/sprite 630003.png",
        CC_CALLBACK_0(SinglePlayerGame::playerSkill2,this));

    skill2->setScale(0.12);
    
    //技能1
    //电
    MenuItemImage* skill1 = MenuItemImage::create(
        "Skill/3/4.png",
        "Skill/3/5.png",
        CC_CALLBACK_0(SinglePlayerGame::playerSkill1,this));

    skill1->setScale(0.06);

    Menu* menu = Menu::create(skill1,skill2,skill3,skill4,NULL);
    menu->alignItemsHorizontallyWithPadding(50.0f);
    menu->setPosition(Vec2(visibleSize.width * 0.5f,visibleSize.height/6));
    this->addChild(menu,11);

    //创建英雄
    Hero = Player1::create();
    Hero->setPosition(Vec2(visibleSize.width/2+origin.x,visibleSize.height/2+origin.y));
    this->addChild(Hero,11);
    //创建敌人(野狼骑士)
    Player* Wolf = Wolf::create();
    Wolf->setPosition(Vec2(visibleSize.width/3+origin.x,visibleSize.height/3+origin.y));
    this->addChild(Wolf,10);

    //创建触屏监听事件
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->onTouchBegan = [=](Touch* touch, Event* event)
    {
        log("触屏%.2f %.2f",touch->getLocation().x,touch->getLocation().y);
        if (touch->getLocation().x - Hero->getPositionX() > 0)
            Hero->playerMove(touch->getLocation().x,touch->getLocation().y,true);
        else
            Hero->playerMove(touch->getLocation().x,touch->getLocation().y,false);
        return true;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
    
    return true;
}

void SinglePlayerGame::playerSkill4()
{
    Hero->playerSkill(0,0,true,4);
}

void SinglePlayerGame::playerSkill3()
{
    log("技能3");
}

void SinglePlayerGame::playerSkill2()
{
    log("技能2");
}

void SinglePlayerGame::playerSkill1()
{
    auto listener1 = EventListenerTouchOneByOne::create();
    Hero->playerSkill(Hero->getPositionX(),Hero->getPositionY(),true,1);
}