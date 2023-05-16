#include "StanGry.hpp"
using namespace sf;
using namespace std;
StanGry::StanGry(RenderWindow* window,map<string,int>*supportedKeys,stack<Stan*>*stany):Stan(window,supportedKeys,stany  )
{

    this->initKeybinds();
    this->initTextures();
    this->initPlayers();
    this->initWalls();


//    this->initViev();

}
StanGry::~StanGry()
{
    delete this->player;
    delete this->player2;
    delete this->wall;
}
void StanGry::initKeybinds()
{
    this->keybinds.emplace("RUSZ_W_LEWO",this->supportedKeys->at("A"));
    this->keybinds.emplace("RUSZ_W_PRAWO",this->supportedKeys->at("D"));
    this->keybinds.emplace("RUSZ_W_GORE",this->supportedKeys->at("W"));
    this->keybinds.emplace("RUSZ_W_DOL",this->supportedKeys->at("S"));

    this->keybinds.emplace("RUSZ_W_LEWO2",this->supportedKeys->at("Left"));
    this->keybinds.emplace("RUSZ_W_PRAWO2",this->supportedKeys->at("Right"));
    this->keybinds.emplace("RUSZ_W_GORE2",this->supportedKeys->at("Up"));
    this->keybinds.emplace("RUSZ_W_DOL2",this->supportedKeys->at("Down"));
//    this->keybinds.emplace("ATAK",this->supportedKeys->at(Mouse::Left));
}
void StanGry::initTextures()
{
    if(!this->textures["PLAYER_SHEET"].loadFromFile("Resorces/Sprites/PLAYER_SHEET.png"))
    {
        throw "ERROR";
    }
    if(!this->textures["WALL_SHEET"].loadFromFile("Resorces/Sprites/wall128x34.png"))
    {
        throw "ERROR";
    }
}
void StanGry::initPlayers()
{

    this->player=new Player(500,500,0.5,0.7,this->textures["PLAYER_SHEET"]);
    this->player2=new Player(0,0,0.5,0.7,this->textures["PLAYER_SHEET"]);



}
void StanGry::initWalls()
{
    for (int i = 0; i < 30; ++i)
    {
        int posX = positions[i][0];
        int posY = positions[i][1];


        Wall* wall = new Wall(posX, posY, 1,1 , this->textures["WALL_SHEET"]);
        walls.push_back(wall);
    }
}

void StanGry::updateKeybinds(const float & dt)
{

    //PLAYER INPUT
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_LEWO"))))
           {
               this->player->move(-1.f,0.f,dt);
           }
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_PRAWO"))))
           {
               this->player->move(1.f,0.f,dt);
              // this->player->setScale(0.5,0.5);
           }
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_GORE"))))
            {
                this->player->move(0.f,-1.f,dt);
            }
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_DOL"))))
            {
                this->player->move(0.f,1.f,dt);
            }
            //Player 2

        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_LEWO2"))))
           {
               this->player2->move(-1.f,0.f,dt);
           }
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_PRAWO2"))))
           {
               this->player2->move(1.f,0.f,dt);
           }
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_GORE2"))))
            {
                this->player2->move(0.f,-1.f,dt);
            }
        if(Keyboard::isKeyPressed(Keyboard::Key(this->keybinds.at("RUSZ_W_DOL2"))))
            {
                this->player2->move(0.f,1.f,dt);
            }
}
void StanGry::update(const float&dt)
{


        this->updateMP();
        this->updateKeybinds(dt);
        this->player->update(dt);
        this->player2->update(dt);
//        this->updateViev(dt);
        for (const auto& wall : walls)
        {
            wall->update(dt);
        }

}
void StanGry::render(RenderTarget*target)
{

    if(!target)
        target=this->window;

        target->setView(this->view);

    this->player->render(*target);
    this->player2->render(*target);

    for (const auto& wall : walls)
    {
        wall->render(*target);
    }


    cout<<player->getPosition().x<<endl;
    cout<<player->getPosition().y<<endl;


}
/*void StanGry::initViev()
{
    this->view.setSize(Vector2f(1920,1080));
    this->view.setCenter(Vector2f(1920/2,1080/2));
}
void StanGry::updateViev(const float& dt)
{
    this->view.setCenter(this->player->getPosition());
}
*/
