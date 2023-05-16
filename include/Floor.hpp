#ifndef FLOOR_H
#define FLOOR_H
#include "C:\Users\giers\Desktop\test2\test2\Entities\Entity.hpp"
using namespace sf;
using namespace std;
class Floor : public  Entity
{
    public:
        Floor(float x,float y,float x1,float y1,Texture& texture);
        virtual ~Floor();

};

#endif // FLOOR_H
