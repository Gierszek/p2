#include "Enemy.hpp"
using namespace sf;
using namespace std;
Enemy::Enemy(float x,float y,float x1,float y1,Texture& texture)
{


    this->setTexture(texture);
    this->setPosition(x,y);
    this->setScale(x1,y1);
    this->createMovement(250.f,15.f,15.f);


}
Enemy::~Enemy()
{

}
void Enemy::update(const float& dt)
 {

    this->movement->update(dt);
 }
