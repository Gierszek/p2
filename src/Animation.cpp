#include "Animation.hpp"
using namespace sf;
using namespace std;
Animation::Animation(Sprite& sprite,Texture& texture_sheet)
    :sprite(sprite),textureSheet(texture_sheet),lastAnimation(NULL),priorityAnimation(NULL)
{

}

Animation::~Animation()
{


    for(auto &i :this->animations)
    {
        delete i.second;
    }
}
//Accesors
const bool& Animation::isDone(const string key)
{
   return this->animations[key]->isDone();
}
//Functions
void Animation::addAnimation(const string key,
        float animation_timer,
        int start_frame_x,int start_frame_y,
        int frames_x,int frames_y,int width,int height)
{
    this->animations[key]=new Animation1(this->sprite,this->textureSheet,
            animation_timer,start_frame_x,
            start_frame_y,frames_x,frames_y,width,height);
}
const bool& Animation::play(const string key,const float& dt,const bool priority)
{

    if(this->priorityAnimation)
    {
        if(this->priorityAnimation==this->animations[key])
        {
            if(this->lastAnimation!=this->animations[key])
            {
                if(this->lastAnimation==NULL)
                {
                    this->lastAnimation=this->animations[key];
                }
                else
                {
                    this->lastAnimation->reset();
                    this->lastAnimation=this->animations[key];
                }
            }
            if(this->animations[key]->play(dt))
            {
                this->priorityAnimation=NULL;
            }
        }
    }
    else
    {
        if(priority)
            {
            this->priorityAnimation=this->animations[key];
            }

        if(this->lastAnimation!=this->animations[key])
        {
            if(this->lastAnimation==NULL)
            {
                this->lastAnimation=this->animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation=this->animations[key];
            }
        }
        this->animations[key]->play(dt);

    }
    return this->animations[key]->isDone();
}

const bool& Animation::play(const string key,const float& dt,const float& modifier,const float& modifier_max,const bool priority)
{
    if(this->priorityAnimation)
    {
        if(this->priorityAnimation==this->animations[key])
        {
            if(this->lastAnimation!=this->animations[key])
            {
                if(this->lastAnimation==NULL)
                {
                    this->lastAnimation=this->animations[key];
                }
                else
                {
                    this->lastAnimation->reset();
                    this->lastAnimation=this->animations[key];
                }
            }

            if(this->animations[key]->play(dt,abs(modifier/modifier_max)))
            {
                this->priorityAnimation=NULL;
            }

        }
    }
    else
    {
        if(priority)
        {
            this->priorityAnimation=this->animations[key];
        }
        if(this->lastAnimation!=this->animations[key])
        {
            if(this->lastAnimation==NULL)
            {
                this->lastAnimation=this->animations[key];
            }
            else
            {
                this->lastAnimation->reset();
                this->lastAnimation=this->animations[key];
            }
        }
        this->animations[key]->play(dt,abs(modifier/modifier_max));
    }

    return this->animations[key]->isDone();
}




