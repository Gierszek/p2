#include "Player.hpp"
using namespace sf;
using namespace std;
Player::Player(float x,float y,float x1,float y1,Texture& texture_sheet)
{
    this->initVariables();

    this->setPosition(x,y);


    this->setScale(x1,y1);
    this->createHitbox(this->sprite,42.f,40.f,42,82);
    this->createMovement(250.f,25.f,15.f);
    //this->movement->velocity.y=250.f;

    this->createAnimation(texture_sheet);

    this->animation->addAnimation("IDLE_LEFT",11.f,0,0,13,0,192,192);
    this->animation->addAnimation("RUSZ_W_LEWO",6.f,0,1,11,1,192,192);
    this->animation->addAnimation("ATAK",5.f,0,2,13,2,192*2,192);
}

Player::~Player()
{
    //dtor
}
//initializer functions
void Player::initVariables()
{
    this->attacking=false;
}
void Player::initComponents()
{

}
//Functions
void Player::updateAttak()
{
    if(Mouse::isButtonPressed(Mouse::Left))
    {
        this->attacking=true;
    }
}
void Player::updateAnimation(const float& dt)
{
   /* if(this->attacking)
    {
        if(this->sprite.getScale().x>0.f)
    {
        this->sprite.setOrigin(96.f,0.f);
    }
    else
    {
        this->sprite.setOrigin(258.f+96.f,0.f);
    }

    if(this->animation->play("ATAK",dt,true))
    {
        this->attacking=false;

        if(this->sprite.getScale().x>0.f)
        {
            this->sprite.setOrigin(0.f,0.f);
        }
        else
        {
            this->sprite.setOrigin(258.f,0.f);
        }
    }
    }
*/

    if(this->movement->getState(IDLE))
        {
            this->animation->play("IDLE_LEFT",dt);
        }
    else if(this->movement->getState(RUCH_W_LEWO))
       {
            if(this->sprite.getScale().x<0.f)
            {
            this->sprite.setOrigin(0.f,0.f);
            this->sprite.setScale(0.5,0.7);
            }
            this->animation->play("RUSZ_W_LEWO",dt,this->movement->getVelocity().x,this->movement->getMaxVelocity());
       }
    else if(this->movement->getState(RUCH_W_PRAWO))
    {
        if(this->sprite.getScale().x>0.f)
            {
         this->sprite.setOrigin(258.f,0.f);
         this->sprite.setScale(-0.5,0.7);
            }
         this->animation->play("RUSZ_W_LEWO",dt,this->movement->getVelocity().x,this->movement->getMaxVelocity());
    }
    else if(this->movement->getState(SKOK))
    {
         this->animation->play("RUSZ_W_LEWO",dt,this->movement->getVelocity().y,this->movement->getMaxVelocity());
    }
    else if(this->movement->getState(UPADEK))
    {
         this->animation->play("IDLE_LEFT",dt,this->movement->getVelocity().y,this->movement->getMaxVelocity());
    }
    else if(this->movement->getState(ATAK))
    {
         this->animation->play("RUSZ_W_LEWO",dt,this->movement->getVelocity().y,this->movement->getMaxVelocity());
    }

}


 void Player::update(const float& dt)
 {

    this->movement->update(dt);
    this->updateAttak();


    this->updateAnimation(dt);

    this->hitbox->update();
 }
