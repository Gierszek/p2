#include "Entity.hpp"
using namespace sf;
using namespace std;
Entity::Entity()
{
        this->initVariables();
}
Entity::~Entity()
{
    delete this->hitbox;
    delete this->movement;
    delete this->animation;


}
void Entity::move(const float dir_x, const float dir_y,const float &dt)
{
    if(this->movement)
    {
        this->movement->move(dir_x,dir_y,dt);
    }

}
void Entity::update(const float& dt)
{

}

void Entity::render(RenderTarget& target)
{

        target.draw(this->sprite);

        if(this->hitbox)
        {
            this->hitbox->render(target);
        }

}
//Component functions
void Entity::setTexture(Texture& texture)
{

    this->sprite.setTexture(texture);
}
 void Entity::initVariables()
 {
     this->hitbox=NULL;
      this->movement=NULL;
      this->animation=NULL;

 }
void Entity::setPosition(const float x,const float y)
{
    this->sprite.setPosition(x,y);
    //this->boundingRectangle.setPosition(x,y);
    if(this->hitbox)
    {
         this->hitbox->setPosition(x,y);
    }
    else
    {
        this->sprite.setPosition(x,y);
    }


}
void Entity::createMovement(const float maxVelocity,const float acceleration,const float deceleration)
{
    this->movement = new Movement(this->sprite,maxVelocity,acceleration,deceleration);
   // this->movement = new Movement(this->boundingRectangle,maxVelocity,acceleration,deceleration);
}
void Entity::setScale(float x1,float y1)
{
    this->sprite.setScale(x1,y1);
}
void Entity::createHitbox(Sprite& sprite,float offset_x,float offset_y,float width,float height)
{
    this->hitbox=new Hitbox(sprite,offset_x,offset_y,width,height);
}
void Entity::createAnimation(Texture& texture_sheet)
{
    this->animation = new Animation(this->sprite,texture_sheet);
}

const Vector2f& Entity::getPosition() const
{
    if(this->hitbox)
    {
        return this->hitbox->getPosition();
    }

    return this->sprite.getPosition();


}
const sf::FloatRect Entity::getGlobalBounds() const
{
    if(this->hitbox)
    {
        return this->hitbox->getGlobalBounds();
    }
    return this->sprite.getGlobalBounds();
}
