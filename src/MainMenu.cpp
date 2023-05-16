#include "MainMenu.hpp"
using namespace sf;
using namespace std;
MainMenu::MainMenu(RenderWindow* window,map<string,int>*supportedKeys,stack<Stan*>*stany):Stan(window,supportedKeys,stany  )
{
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();


}


MainMenu::~MainMenu()
{
   auto it=this->buttons.begin();
   for(it=this->buttons.begin();it!=this->buttons.end();++it)
   {
       delete it->second;
   }

}
void MainMenu::initKeybinds()
{

}
void MainMenu::updateKeybinds(const float & dt)
{

    //PLAYER INPUT


}

void MainMenu::update(const float&dt)
{
        this->updateMP();
        this->updateKeybinds(dt);

        this->updateb();



}
void MainMenu::updateb()
{
    //update buttons
    for(auto &it:this->buttons)
    {
        it.second->update(this->mousePV);
    }
    //new
    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->stany->push(new StanGry(this->window,this->supportedKeys,this->stany));
    }
    if(this->buttons["EXIT_STATE"]->isPressed())
        {
            exit(0);
        }
}

void MainMenu::render(RenderTarget*target)
{

    if(!target)
        target=this->window;
        target->draw(this->background);
       this->renderb(*target);
       //remove later/!
        Text mouseText;
        mouseText.setPosition(this->mousePV.x,this->mousePV.y-50);
        mouseText.setFont(this->font);
        mouseText.setCharacterSize(20);
        stringstream ss;
        ss<<this->mousePV.x<<" "<<this->mousePV.y;
        mouseText.setString(ss.str());

        target->draw(mouseText);
}
void MainMenu::renderb(RenderTarget& target)
{
    for(auto &it:this->buttons)
    {
        it.second->render(target);
    }
}
void MainMenu::initFonts()
{
    if(!this->font.loadFromFile("GreatVibes-Regular.otf"))
    {
        throw("Could not load font");

    }
}
void MainMenu::initButtons()
{
    this->buttons["GAME_STATE"]=new Button(350.f,350.f,350.f,200.f,
                            &this->font,"New Game",
                            64.f,
                            Color(250,250,250,250),Color(70,70,70,200),Color(20,20,20,50),
                            Color(70,70,70,0),Color(150,150,150,0),Color(20,20,20,0)
                            );

    this->buttons["EXIT_STATE"]=new Button(350,600,350,200,&this->font,"Quit",
                               64.f,
                            Color(250,250,250,250),Color(70,70,70,200),Color(20,20,20,50),
                            Color(70,70,70,0),Color(150,150,150,0),Color(20,20,20,0)
                            );
}
void MainMenu::initBackground()
{
    this->background.setSize(
        Vector2f(static_cast<float>(this->window->getSize().x),
                 static_cast<float>(this->window->getSize().y)));
    if(!this->bgTexture.loadFromFile("Resorces/Images/Backgrounds/fawb.jpg"))
    {
        throw"failed to load bg1";
    }
    this->background.setTexture(&this->bgTexture);
}
void MainMenu::initVariables()
{

}
