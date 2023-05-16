#pragma once
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
enum buttonst{BTN_IDLE=0,BTN_HOVER,BTN_ACTIVE};

class Button
{
    public:
        Button(float x,float y,float width,float height,Font* font,
               string text,unsigned character_size,Color text_color,Color text_hover_color,Color text_active_color,Color icolor,Color hcolor, Color acolor);
         ~Button();
        void update(const Vector2f mousePos);
    void render (RenderTarget& target);

    const bool isPressed()const;
    private:
        short unsigned buttonStan;
        bool pressed;
        bool hover;

        RectangleShape shapeb;
        Font*font;
        Text text;
        Color textIdleColor;
        Color textHoverColor;
        Color textActiveColor;
        Color icolor;
        Color hcolor;
        Color acolor;


};
