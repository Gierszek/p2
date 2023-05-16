#include "Stan.hpp"
using namespace sf;
using namespace std;
Stan::Stan(sf:: RenderWindow* window,map<string,int>*supportedKeys,stack<Stan*>*stany)
{

    this->window = window;
    this->supportedKeys=supportedKeys;
    this->stany=stany;
    this-> quit=false;
}
Stan::~Stan()
{

}

const bool& Stan::getQuit() const
{
    return this->quit;
}
void Stan::endStan()
{
    this->quit=true;
}
 void  Stan::updateMP()
 {
     this->mousePS= Mouse::getPosition();
     this->mousePW= Mouse::getPosition(*this->window);
     this->mousePV= this->window->mapPixelToCoords(Mouse::getPosition(*this->window));
 }
