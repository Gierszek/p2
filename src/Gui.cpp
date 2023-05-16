#include "gui.hpp"
using namespace sf;
using namespace std;
Gui::Gui(float x,float y,float x1,float y1,Texture& texture)
{


    this->setTexture(texture);
    this->setPosition(x,y);
    this->setScale(x1,y1);
    this->createMovement(350.f,15.f,5.f);


}
Gui::~Gui()
{

}
void Gui::update(const float& dt)
 {

    this->movement->update(dt);
 }
