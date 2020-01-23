#ifndef BULLET_H
#define BULLET_H
#include "../include/data.h"
#include "bulletdata.hpp"
#include "gunshot.hpp"
#include <SFML/Audio.hpp>

class Bullet
{
    public:
        Bullet(Vector2f size, Vector2f position);
        Bullet();
        virtual ~Bullet();
        void drawTo(RenderWindow& twindow);
        void move(Vector2f direction);
        void setPosition(Vector2f position);
        void setRotation(float rotation);
        void playGunshot();
        bool fireBulletMessage;
        bool isBeingFired;
        Vector2f getPosition();
        float getPositionX();
        float getPositionY();
        float getRotation();
        float velocity;
    protected:

    private:
        Texture* bTexture;
        Sprite* bSprite;
        SoundBuffer bgunshot;
        Sound gunshot;
};

#endif // BULLET_H
