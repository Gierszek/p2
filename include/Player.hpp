#ifndef PLAYER_H
#define PLAYER_H
#include "../Entities/Entity.hpp"
using namespace sf;
using namespace std;
class Player: public Entity
{
    private:
    bool attacking;
    View view;
    //initializers
    void initVariables();
    void initComponents();

    public:
        Player(float x,float y,float x1,float y1,Texture& texture_sheet);
        virtual ~Player();


   void updateAttak();

    void updateAnimation(const float& dt);
    virtual void update(const float& dt);


};

#endif // PLAYER_H
