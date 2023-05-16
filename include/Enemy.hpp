#ifndef ENEMY_H
#define ENEMY_H
#include "C:\Users\giers\Desktop\test2\test2\Entities\Entity.hpp"
using namespace sf;
using namespace std;
class Enemy : public Entity
{


    public:
    Enemy(float x,float y,float x1,float y1,Texture& texture);
    virtual ~Enemy();

    virtual void update(const float& dt);

};

#endif

