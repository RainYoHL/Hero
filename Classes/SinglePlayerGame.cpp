#include "SinglePlayerGame.h"

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

    return true;
}