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
    return true;
}