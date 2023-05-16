#ifndef WALL_H
#define WALL_H
#include "../Entities/Entity.hpp"

class Wall: public Entity
{
    private:
    public:
        Wall(float x,float y,float x1,float y1,Texture& texture_sheet);
        virtual ~Wall();
        void updateAnimation(const float& dt);
    virtual void update(const float& dt);

};

#endif // WALL_H
