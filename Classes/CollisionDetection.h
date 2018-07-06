#ifndef _CollisionDetection_H
#define _CollisionDetection_H

#include "cocos2d.h"
#include "Enemy.h"
#include "PlayerSkill1.h"
USING_NS_CC;

class CollisionDetection : public Node
{
public:
    CREATE_FUNC(CollisionDetection);
    virtual bool init();
    void update(float dt);
};
#endif