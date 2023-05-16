#pragma once
#include "../Entities/Entity.hpp"
using namespace sf;
using namespace std;
class Stan
{
private:

protected:
    sf:: RenderWindow* window;
    stack<Stan*>*stany;
    map<string,int>* supportedKeys;
    map<string,int> keybinds;
    bool quit;
    Vector2i mousePS;
     Vector2i mousePW;
     Vector2f mousePV;

    //resorses
        map<string,sf::Texture> textures;

        //functions

        void initKeybinds();
public:
    Stan(sf:: RenderWindow* window,map<string,int>*supportedKeys,stack<Stan*>*stany);
    virtual ~Stan();
    const bool& getQuit() const;
    virtual void updateKeybinds(const float&dt)=0;
    void endStan();
    virtual void updateMP();
    virtual void update(const float&dt) = 0;
    virtual void render(sf::RenderTarget* target=NULL) = 0;
};
