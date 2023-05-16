#include "Button.hpp"
using namespace sf;
using namespace std;
Button::Button(float x,float y,float width,float height,Font* font,
               string text,unsigned character_size,Color text_color,Color text_hover_color,Color text_active_color,Color icolor,Color hcolor, Color acolor)
{
    this->buttonStan= BTN_IDLE;

    this->shapeb.setPosition(Vector2f(x,y));
    this->shapeb.setSize(Vector2f(width,height));
    this->shapeb.setFillColor(icolor);


    this->font=font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(text_color);
    this->text.setCharacterSize(character_size);
    this->text.setPosition(
        this->shapeb.getPosition().x+(this->shapeb.getGlobalBounds().width/2.f) - this->text.getGlobalBounds().width/2.f,
        this->shapeb.getPosition().y+(this->shapeb.getGlobalBounds().height/2.f) - this->text.getGlobalBounds().height/2.f);

    this->textIdleColor= text_color;
    this->textHoverColor= text_hover_color;
    this->textActiveColor= text_active_color;

    this->icolor=icolor;
    this->hcolor=hcolor;
    this->acolor=acolor;

}


Button::~Button()
{

}
const bool Button::isPressed()const
{
    if(this->buttonStan==BTN_ACTIVE)
       {
           return true;
       }

    return false;
}
void Button::render (RenderTarget& target)
{
    target.draw(this->shapeb);
    target.draw(this->text);
}
void Button::update(const Vector2f mousePos)
{
    //HOVER
    this->buttonStan=BTN_IDLE;
    if(this->shapeb.getGlobalBounds().contains(mousePos))
    {
        ////PRESSED
        this->buttonStan=BTN_HOVER;
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            this->buttonStan=BTN_ACTIVE;
        }
    }
    switch(this->buttonStan)
    {
    case BTN_IDLE:
    {
      this->shapeb.setFillColor(this->icolor);
      this->text.setFillColor(this->textIdleColor);
    break;
    }
    case BTN_HOVER:
    {
    this->shapeb.setFillColor(this->hcolor);
    this->text.setFillColor(this->textHoverColor);
    break;
    }
    case BTN_ACTIVE:
    {
    this->shapeb.setFillColor(this->acolor);
    this->text.setFillColor(this->textActiveColor);
    break;
    }
    default:
    {
    this->shapeb.setFillColor(Color::Blue);
    this->text.setFillColor(Color::Blue);
    break;
    }
    }
}
