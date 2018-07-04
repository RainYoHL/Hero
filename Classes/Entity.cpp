#include "PlayScene.h"
#include "Entity.h"

Entity::Entity()
{
    m_sprite = NULL;
}

Entity::~Entity(){}   

Sprite* Entity::getSprite()
{
    return this->m_sprite;
}

void Entity::bindSprite(Sprite* sprite)
{
    this->m_sprite = sprite;
    this->addChild(m_sprite);

    Size spriteSize = m_sprite->getContentSize();
    m_sprite->setPosition(Vec2(spriteSize.width * 0.5f ,spriteSize.height * 0.5f));
    this->setAnchorPoint(Vec2(0.5,0.5));
    //log("初始化：%.2f %.2f",spriteSize.width,spriteSize.height);
    this->setContentSize(spriteSize);
}