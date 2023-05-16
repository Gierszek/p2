#ifndef GUI_H
#define GUI_H
#include "C:\Users\giers\Desktop\test2\test2\Entities\Entity.hpp"
using namespace sf;
using namespace std;

class Gui : public Entity
{


    public:
    Gui(float x,float y,float x1,float y1,Texture& texture);
    virtual ~Gui();

    virtual void update(const float& dt);

};

#endif






