#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Stany/StanGry.hpp"
#include "MainMenu.hpp"
using namespace sf;
using namespace std;


class game
{
private:
    RenderWindow *window;
    Event sfEvent;
    vector<VideoMode> videomodes;
    ContextSettings windowset;
    bool fullscreen;
    Clock dtClock;
    float dt;



    std::stack<Stan*> stany;

    void initVariables();
    void initWindow();
    void initStany();
    void inicjokna();
    void initKeys();
    void setViev();
    map<string,int>supportedKeys;


public:
    game();
    virtual ~game();

//Functions
void updatedt();
void update();
void updateSFMLevent();
void render();
void run();

};

