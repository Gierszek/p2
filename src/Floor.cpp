#include "Floor.hpp"
using namespace sf;
using namespace std;
Floor::Floor(float x,float y,float x1,float y1,Texture& texture)
{
this->setTexture(texture);
     this->setPosition(x,y);
}

Floor::~Floor()
{

}
