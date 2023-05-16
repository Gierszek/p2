#include "Wall.h"

Wall::Wall(float x,float y,float x1,float y1,Texture& texture_sheet)
{
    this->setPosition(x,y);
    this->setScale(x1,y1);
    this->createAnimation(texture_sheet);
    this->createHitbox(this->sprite,0.f,0.f,128,34);
    this->createMovement(0.f,0.f,0.f);
    this->animation->addAnimation("IDLE_LEFT",11.f,0,0,13,0,128,34);
}

Wall::~Wall()
{
    //dtor
}
void Wall::update(const float& dt)
 {

    this->movement->update(dt);
    this->hitbox->update();
}
void Wall::updateAnimation(const float& dt)
{

}

