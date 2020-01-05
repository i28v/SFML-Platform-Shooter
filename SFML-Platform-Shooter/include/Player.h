#ifndef PLAYER_H
#define PLAYER_H
#include "data.h"
#include "Playerdata.hpp"


class Player
{
    public:
        Player(Vector2f size, Vector2f position);
        virtual ~Player();
        void drawTo(RenderWindow& twindow);
        void setDirection(Direction dir);
        void move(Vector2f direction);
        Vector2f getPosition();
        float getPositionX();
        float getPositionY();
        Direction getDirection();
    protected:

    private:
        Texture* pTexture;
        Sprite* pSprite;
        Direction pDir;
};

#endif // PLAYER_H
