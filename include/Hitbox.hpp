#ifndef HITBOX_H
#define HITBOX_H

#include "C:\\Users\\giers\\Desktop\\test2\\test2\\include\\Movement.hpp"
using namespace sf;
using namespace std;
class Hitbox
{

    private:
        Sprite& sprite;
        RectangleShape hitbox;
        float offsetX;
        float offsetY;

    public:
        Hitbox(Sprite& sprite,
               float offset_x,float offset_y,
               float width,float height);

    virtual ~Hitbox();
    //Functions
    bool checkIntersect(const FloatRect& frect);
    void update();
    void render(RenderTarget& target);
};

#endif // HITBOX_H
