#include "Rectangles.hpp"
using namespace sf;
using namespace std;
Rectangles::Rectangles(float x,float y)
{
    this->initVariables();
    this->initComponents();
    this->setPosition(x,y);
    this->initializeRectangle();
}

Rectangles::~Rectangles()
{
    //dtor
}
void Rectangles::initVariables()
{

}
void Rectangles::initComponents()
{
    this->createMovement(300.f,15.f,5.f);
}
