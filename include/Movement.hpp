#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include<stack>
#include <map>

using namespace sf;
using namespace std;
enum movement_states{IDLE=0,RUCH,RUCH_W_LEWO,RUCH_W_PRAWO,SKOK,UPADEK,ATAK};
class Movement
{
    public:
        Movement(Sprite& sprite,float maxVelocity,float acceleration, float deceleration);
        virtual ~Movement();

        //Functions
        void move(const float x, const float y, const float& dt);
        void update(const float& dt);
        //Accessors
        const float& getMaxVelocity() const;
        const Vector2f& getVelocity() const;

        const bool getState(const short unsigned state) const;
        const bool idle() const;
        const bool moving() const;
        const bool movingLeft() const;
        const bool movingRight() const;

        Sprite& sprite;

        float maxVelocity;
        Vector2f velocity;
        float acceleration;
        float deceleration;
        //initializer functions
};

#endif // MOVEMENT_H
