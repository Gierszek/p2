#pragma once
#include "../include/Movement.hpp"
#include "../include/Hitbox.h"
#include "../include/Animation.hpp"
//#include "../include/Wall.h"
using namespace sf;
using namespace std;

class Entity:Sprite
{
public:
void initVariables();


Sprite sprite;

Hitbox* hitbox;
RectangleShape boundingRectangle;
Movement* movement;
Animation* animation;
map<string,sf::Texture> textures;
 //const sf::Vector2f& getPosition() const;


    void setRotationOrigin(float origin_x, float origin_y);
    sf::Vector2f getRotationOrigin() const;


    Entity();
    virtual ~Entity();
    //component functions
    void setTexture(Texture& texture);
    void createHitbox(Sprite& sprite,float offset_x,float offset_y,
                float width,float height);
    void createMovement(const float maxVelocity,const float acceleration,const float deceleration);
    void createAnimation(Texture& texture_sheet);

    //Accesors
    virtual const Vector2f& getPosition() const;
    virtual const sf::FloatRect getGlobalBounds() const;
    //Modifiers

    //Functions
    virtual void update(const float& dt);
    virtual void render(RenderTarget& target);
    virtual void move(const float x, const float y,const float &dt);
    virtual void setPosition(const float x,const float y);
    virtual void setScale(const float x1,const float y1);


};
