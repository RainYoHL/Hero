#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "SinglePlayerGame.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //创建菜单
    //auto singleBeginGame = Label::createWithSystemFont("单人游戏","Microsoft YaHei",20);
    auto singleBeginGame = Label::createWithTTF("SinglePlayer Game", "fonts/Marker Felt.ttf", 20);
    singleBeginGame->setColor(Color3B(0,0,0));
    auto singleBeginGameItem = MenuItemLabel::create(singleBeginGame,CC_CALLBACK_0(HelloWorld::changeToSinglePlayerGame,this));

    //auto multiBeginGame = Label::createWithSystemFont("多人游戏","Microsoft YaHei",20);
    auto multiBeginGame= Label::createWithTTF("MultiPlayer Game", "fonts/Marker Felt.ttf", 20);
    multiBeginGame->setColor(Color3B(0,0,0));
    auto multiBeginGameItem = MenuItemLabel::create(multiBeginGame,CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));

    //auto exitGame = Label::createWithSystemFont("退出游戏","Microsoft YaHei",20);
    auto exitGame = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 20);
    exitGame->setColor(Color3B(0,0,0));
    auto exitGameItem = MenuItemLabel::create(exitGame,CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));

    auto menu = Menu::create(singleBeginGameItem,multiBeginGameItem,exitGameItem ,NULL);
    menu->alignItemsVerticallyWithPadding(10);
    menu->setPosition(visibleSize.width/2+origin.x , visibleSize.height/2+origin.y);
    this->addChild(menu, 1);

    //标题
    auto label = Label::createWithTTF("Hero Game", "fonts/Marker Felt.ttf", 24);
    label->setColor(Color3B(0,0,0));
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));
    this->addChild(label, 1);

    auto background_image = Sprite::create("Map/Map72/image2.png");
    background_image->setPosition(Vec2(visibleSize.width/2+origin.x,
                                       visibleSize.height/2+origin.y));
    //适配屏幕分辨率
    background_image->setScaleX(visibleSize.width/background_image->getTextureRect().getMaxX());
	background_image->setScaleY(visibleSize.height/background_image->getTextureRect().getMaxY());
    this->addChild(background_image);

   
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::changeToSinglePlayerGame()
{
    auto singlePlayerScene = SinglePlayerGame::create();
    Director::getInstance()->replaceScene(singlePlayerScene);
}