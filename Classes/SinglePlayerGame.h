#ifndef __SinglePlayerGame_SCENE_H__
#define __SinglePlayerGame_SCENE_H__

#include "cocos2d.h"
#include "Player.h"

class SinglePlayerGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    

    void playerSkill4();

    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(SinglePlayerGame);
private:
    Player* Hero;
};

#endif 
