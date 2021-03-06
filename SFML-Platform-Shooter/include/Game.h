#ifndef GAME_H
#define GAME_H
#include "data.h"
#include "settings.h"
#include "Player.h"
#include "Bullet.h"

class Game
{
    public:
        Game();
        virtual ~Game();
        void start();
    protected:

    private:
    RenderWindow* window;
    Event* event;
    RectangleShape* grass;
    Player* player;
    Clock fireBulletClock;
    Clock spacebarClock;
    Time spacebarTime;
    Time fireTime;
    std::vector<Bullet*> bullet;
    unsigned int numberOfBulletsBeingFired;
    bool fireBulletMessage;
    void init();
    void events(RenderWindow& twindow, Event& tevent);
    void input();
    void update();
    void draw(RenderWindow& twindow);

    bool paused;
};

#endif // GAME_H
