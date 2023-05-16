#include "game.hpp"
#include <iostream>

//CONSTRUKTORS/DESTRUCTORS
using namespace sf;
using namespace std;
game::game()
{
    //initialize window
    this->inicjokna();
    this->initKeys();
    this->initStany();

};

game::~game()
{
    delete this->window;
    while(!this->stany.empty())
    {
        delete this->stany.top();
        this->stany.pop();
    }
};
void game::inicjokna()
{
    ifstream bd("Config/window.ini");
    this->videomodes=VideoMode::getFullscreenModes();

    string title = "None";
    VideoMode window_bounds=VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerate_limit =60;
    bool vertical_sync_enabled = false;
    unsigned antialiasing = 0;
    if(bd.is_open())
    {
        getline(bd,title);
        bd>>window_bounds.width>>window_bounds.height;
        bd>>fullscreen;
        bd>>framerate_limit;
        bd>>vertical_sync_enabled;
        bd>>antialiasing;
    }
    bd.close();
    this->fullscreen=fullscreen;
    this->windowset.antialiasingLevel=antialiasing;

    if(this->fullscreen)
        this->window = new RenderWindow(window_bounds,
                        title,Style::Fullscreen,windowset);
    else
                        this->window = new RenderWindow(window_bounds,
                        title,Style::Titlebar|Style::Close,windowset);

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

//Functions
void game::initKeys()
{
    this->supportedKeys.emplace("Escape",Keyboard::Key::Escape);
    this->supportedKeys.emplace("A",Keyboard::Key::A);
    this->supportedKeys.emplace("D",Keyboard::Key::D);
    this->supportedKeys.emplace("W",Keyboard::Key::W);
    this->supportedKeys.emplace("S",Keyboard::Key::S);

    this->supportedKeys.emplace("Up",Keyboard::Key::Up);
    this->supportedKeys.emplace("Right",Keyboard::Key::Right);
    this->supportedKeys.emplace("Left",Keyboard::Key::Left);
    this->supportedKeys.emplace("Down",Keyboard::Key::Down);


}
void game::initWindow()
{

}
void game::initStany()
{
    this->stany.push(new MainMenu(this->window,&this->supportedKeys,&this->stany));

}
void game::updatedt()
{
    // updates the dt variable
    this->dt=this->dtClock.restart().asSeconds();

}
void game::updateSFMLevent()
{
    while(this->window->pollEvent(this->sfEvent))
    {
        if(this->sfEvent.type == Event::Closed)
            this->window->close();
    }
}

void game::update()
{
    this->updateSFMLevent();

    if(!this->stany.empty())
    {
        this->stany.top()->update(this->dt);
        if(this->stany.top()->getQuit())
        {
            this->stany.top()->endStan();
            delete this->stany.top();
            this->stany.pop();
        }
    }
}

void game::render()
{
    //render things
    this->window->clear();
    if(!this->stany.empty())
        this->stany.top()->render();
    this->window->display();


}

void game::run()
{
    while (this->window->isOpen())
    {
        this->updatedt();
        this->update();
        this->render();

    }
}
void game::initVariables()
{
    this->window=NULL;
    this->fullscreen=false;
    this->dt=0.f;
}


