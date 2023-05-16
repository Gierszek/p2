#include "Movement.hpp"
using namespace sf;
using namespace std;
Movement::Movement(Sprite& sprite,float maxVelocity,float acceleration, float deceleration ): sprite(sprite), maxVelocity(maxVelocity),acceleration(acceleration),deceleration(deceleration)
{
    this->maxVelocity= maxVelocity;
}

Movement::~Movement()
{
    //dtor
}
void Movement::update(const float& dt)
{
    //decelerates sprite, controls maximum velocity,moving
    if(this->velocity.x>0.f)//Check for pos x
    {
        //max velocity check
        if(this->velocity.x>this->maxVelocity)
        this->velocity.x=this->maxVelocity;

        //deceleration x
        this->velocity.x -= deceleration;
        if(this->velocity.x<0.f)
        this->velocity.x=0.f;
    }
    else if(this->velocity.x<0.f)//check for neg x
    {
        //max velocity check
        if(this->velocity.x< -this->maxVelocity)
        this->velocity.x= -this->maxVelocity;
        //deceleration x
        this->velocity.x += deceleration;
        if(this->velocity.x>0.f)
            this->velocity.x=0.f;
    }

   if(this->velocity.y>0.f)//Check for pos y
    {
        //max velocity check
        if(this->velocity.y>this->maxVelocity)
        this->velocity.y=this->maxVelocity;

        //deceleration y pos
        this->velocity.y -= deceleration;
        if(this->velocity.y<0.f)
        this->velocity.y=0.f;

    }
    else if(this->velocity.y<0.f)//check for neg y
    {
        //max velocity check neg
        if(this->velocity.y< -this->maxVelocity)
            this->velocity.y= -this->maxVelocity;

        this->velocity.y += deceleration;
       if(this->velocity.y>0.f)
            this->velocity.y=0.f;
    }

    //final move
    this-> sprite.move(this->velocity*dt);
    //cout<<velocity.x<<endl;
    //cout<<velocity.y<<endl;
}
void Movement::move(const float dir_x, const float dir_y, const float& dt)
{
    //Acceleration

    this->velocity.x+=this->acceleration*dir_x;
    this->velocity.y+=this->acceleration*dir_y;
    //cout<<acceleration<<endl;

}
const Vector2f& Movement::getVelocity() const
{
    return this->velocity;
}

const bool Movement::getState(const short unsigned state) const
{
    switch(state)
    {
    case IDLE:
        if(this->velocity.x==0.f && this->velocity.y==0.f)
    return true;
        break;
    case RUCH:
        if(this->velocity.x!=0.f || this->velocity.y!=0.f)
    return true;
        break;

    case RUCH_W_LEWO:
        if(this->velocity.x<0.f)
    return true;
        break;

    case RUCH_W_PRAWO:
        if(this->velocity.x>0.f)
    return true;
        break;

    case SKOK:
        if(this->velocity.y<0.f)
    return true;
        break;

    case UPADEK:
        if(this->velocity.y>0.f)
    return true;
        break;

    case ATAK:
        if(Mouse::isButtonPressed(Mouse::Left))
    return true;
        break;
    }

    return false;
}
const float& Movement::getMaxVelocity() const
{
    return this->maxVelocity;
}
