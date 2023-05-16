#ifndef ANIMATION_H
#define ANIMATION_H

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
#include "../include/Movement.hpp"
using namespace sf;
using namespace std;
class Animation
{
private:
class Animation1
{
    public:
    Sprite& sprite;
    Texture&  textureSheet;
    float animationTimer;
    float timer;
    bool done;
    int width;
    int height;
    IntRect startrect;
    IntRect currentrect;
    IntRect endrect;
    Animation1(Sprite& sprite,Texture&  textureSheet,
        float animation_timer,
        int start_frame_x,int start_frame_y,int frames_x,int frames_y,int width,int height)
    :sprite(sprite),textureSheet(textureSheet),animationTimer(animation_timer),timer(0.f),done(false),width(width),height(height)
    {
        this->timer=0.f;
        this->startrect = IntRect(start_frame_x*width,start_frame_y*height,width,height);
        this->currentrect=this->startrect;
        this->endrect = IntRect(frames_x*width,frames_y*height,width,height);


        this->sprite.setTexture(this->textureSheet,true);
        this->sprite.setTextureRect(this->startrect);
    }
    //Accessor
    const bool& isDone() const{return this->done;}

    //Functions
    const bool& play(const float& dt)
    {
        this->done=false;
        this->timer+=100.f*dt;
        if(this->timer>=this->animationTimer)
        {
            this->timer=0.f;

            if(this->currentrect!=this->endrect)
            {
                this->currentrect.left+=this->width;
            }
            else
            {
                this->currentrect.left=this->startrect.left;
                this->done =true;

            }
            this->sprite.setTextureRect(this->currentrect);
        }
        return this->done;
    }

    const bool& play(const float& dt,float mod_percent)
    {
        this->done=false;
        if(mod_percent<0.5f)
            mod_percent=0.5;
        this->timer+=(mod_percent)*100.f*dt;
        if(this->timer>=this->animationTimer)
        {
            this->timer=0.f;

            if(this->currentrect!=this->endrect)
            {
                this->currentrect.left+=this->width;
            }
            else
            {
                this->currentrect.left=this->startrect.left;
                this->done=true;

            }
            this->sprite.setTextureRect(this->currentrect);
        }
        return this->done;
    }
    void reset()
    {
        this->timer=this->animationTimer;
        this->currentrect=this->startrect;
    }
};
Sprite& sprite;
Texture& textureSheet;
map<string,Animation1*> animations;
Animation1* lastAnimation;
Animation1* priorityAnimation;
public:

    Animation(Sprite& sprite,Texture& texture_sheet);
    virtual ~Animation();
    //Accesor
    const bool& isDone(const string key);

    //Functions
    void addAnimation(const string key,
        float animation_timer,
        int start_frame_x,int start_frame_y,int frames_x,int frames_y,int width,int height);

    const bool& play(const string key,const float& dt,const bool priority = false);
    const bool& play(const string key,const float& dt,const float& modifier,const float& modifier_max,const bool priority = false);


};

#endif // ANIMATION_H
