#include "Hitbox.h"

Hitbox::Hitbox(sf::Sprite& sprite,
               float offset_x,float offset_y,
               float width,float height)
               :sprite(sprite),offsetX(offset_x),offsetY(offset_y)
{
    this->hitbox.setPosition(this->sprite.getPosition().x+offset_x,this->sprite.getPosition().y+offset_y);
    this->hitbox.setSize(sf::Vector2f(width,height));
    this->hitbox.setFillColor(sf::Color::Transparent);
    this->hitbox.setOutlineThickness(1.f);
    this->hitbox.setOutlineColor(sf::Color::White);
}

Hitbox::~Hitbox()
{
    //dtor
}
void Hitbox::update()
{
    this->hitbox.setPosition(this->sprite.getPosition().x+this->offsetX,this->sprite.getPosition().y+this->offsetY);
}
void Hitbox::render(sf::RenderTarget& target)
{
    target.draw(this->hitbox);
}
bool Hitbox::intersects(const sf:: FloatRect& frect)
{
    return this->hitbox.getGlobalBounds().intersects(frect);
}
//Axxessors
const sf::Vector2f& Hitbox::getPosition() const
{
    return this->hitbox.getPosition();
}

//Modifiers
void Hitbox::setPosition(const sf::Vector2f& position)
{
    this->hitbox.setPosition(position);
    this->hitbox.setPosition(position.x-this->offsetX,position.y-this->offsetY);
}
void Hitbox::setPosition(const float x,const float y)
{
    this->hitbox.setPosition(x,y);
    this->hitbox.setPosition(x-this->offsetX,y-this->offsetY);
}
const sf::FloatRect Hitbox::getGlobalBounds() const
{
    return this->hitbox.getGlobalBounds();
}
