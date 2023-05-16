#pragma once

#include "../include/Wall.h"
#include "../include/Player.hpp"
#include "../include/Button.hpp"
#include "../include/Hitbox.h"
#include "../Stan.hpp"
#include <cmath>
using namespace sf;
using namespace std;

class StanGry : public Stan
{
private:
View view;
RenderTexture renderTexture;

Player* player;
Player* player2;
vector<Wall*> walls;
vector<sf::RectangleShape> wrect;

Wall* wall;
map<string,Button*>buttons;
Font font;
//Functions
//void initViev();
//void updateViev(const float& dt);
void initKeybinds();
void initTextures();
void initPlayers();
void initWalls();
void initHitbox();
void intersect();



public:
    StanGry(sf::RenderWindow* window,map<string,int>*supportedKeys,stack<Stan*>*stany);
    virtual ~StanGry();
    //FUNCTIONS
    void updateKeybinds(const float& dt);


    void update(const float&dt);
    void render (RenderTarget*target=nullptr);

    bool change=false;

int positions[30][2] = {
        {0, window->getSize().y-114},
        {128, window->getSize().y-114},
        {256, window->getSize().y-114},
        {384, window->getSize().y-114},
        {4*128, window->getSize().y-114},
        {5*128, window->getSize().y-114},
        {6*128, window->getSize().y-114},
        {7*128, window->getSize().y-114},
        {-64, window->getSize().y-114-34*5},
        {64, window->getSize().y-114-34*5},

        {128,window->getSize().y-114-34*5},
        {128, window->getSize().y-114},
        {7*128+32, window->getSize().y-114-4*34},
        {7*128, window->getSize().y-114-3*34},
        {7*128, window->getSize().y-114-2*34},
        {5*128, window->getSize().y-114-7*34},
        {5.5*128, window->getSize().y-114-7*34},
        {4*128, window->getSize().y-114-7*34},
        {3*128, window->getSize().y-114-7*34},
        {0*128, window->getSize().y-114-10*34},

        {1*128, window->getSize().y-114-10*34},
        {2*128, window->getSize().y-114-10*34},
        {1*128, window->getSize().y-114-15*34},
        {2*128, window->getSize().y-114-15*34},
        {3*128, window->getSize().y-114-14.5*34},
        {4*128, window->getSize().y-114-14.5*34},
        {5*128, window->getSize().y-114-14.5*34},
        {6*128, window->getSize().y-114-14.5*34},
        {7*128, window->getSize().y-114-14.5*34},
        {7*128, window->getSize().y-114-1*34},
    };
};
