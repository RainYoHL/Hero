#ifndef __SinglePlayerGame_SCENE_H__
#define __SinglePlayerGame_SCENE_H__

#include "cocos2d.h"

class SinglePlayerGame : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);

    
    CREATE_FUNC(SinglePlayerGame);
};

#endif 
