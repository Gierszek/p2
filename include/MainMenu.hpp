#ifndef MAINMENU_H
#define MAINMENU_H

#include "../include/Button.hpp"
#include "../Stany/StanGry.hpp"
#include "../Stan.hpp"
using namespace sf;
using namespace std;
class MainMenu:public Stan
{
    private:

//Functions
void initKeybinds();
void initFonts();
void initButtons();
void initBackground();
void initVariables();
//Variables
Texture bgTexture;
RectangleShape background;
Font font;

map<string,Button*>buttons;
public:
    MainMenu(sf::RenderWindow* window,map<string,int>*supportedKeys,stack<Stan*>*stany);
    virtual ~MainMenu();
    //FUNCTIONS
    void updateKeybinds(const float& dt);

    void updateb();
    void update(const float&dt);
    void renderb(RenderTarget& target);
    void render (RenderTarget*target=nullptr);
};

#endif // MAINMENU_H
