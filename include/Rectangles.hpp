#ifndef RECTANGLES_H
#define RECTANGLES_H
#include "C:\Users\giers\Desktop\test2\test2\Entities\Entity.hpp"
using namespace sf;
using namespace std;
class Rectangles:public Entity
{
    public:
        Rectangles(float x,float y);
        virtual ~Rectangles();

    protected:

    private:
        void initVariables();
        void initComponents();
};

#endif // RECTANGLES_H
