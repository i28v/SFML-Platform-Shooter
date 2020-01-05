#include "../include/Game.h"

Game::Game()
{

}

void Game::init()
{

    this->window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, WINDOW_DATA);
    this->event = new Event();
    this->grass = new RectangleShape();
    this->grass->setSize({800.0f, 250.0f});
    this->grass->setPosition(0.0, 400.0);
    this->grass->setFillColor(Color::Green);
    this->player = new Player({3.0f,3.0f}, {30.0f, 420.0f});
}

Game::~Game()
{
    delete[] this->window;
    delete[] this->event;
    delete[] this->grass;
    delete[] this->player;
}

void Game::events(RenderWindow& twindow, Event& tevent)
{
    while(twindow.pollEvent(tevent))
    {
        if(tevent.type == Event::Closed)
        {
            twindow.close();
            exit(0);
        }
    }
}

void Game::input()
{
    if(kb::isKeyPressed(kb::Up)) this->player->setDirection(Direction::Up);
    if(kb::isKeyPressed(kb::Down)) this->player->setDirection(Direction::Down);
    if(kb::isKeyPressed(kb::Left)) this->player->setDirection(Direction::Left);
    if(kb::isKeyPressed(kb::Right)) this->player->setDirection(Direction::Right);
    else if(!kb::isKeyPressed(kb::Up) && !kb::isKeyPressed(kb::Down) && !kb::isKeyPressed(kb::Left) && !kb::isKeyPressed(kb::Right)) this->player->setDirection(Direction::Still);
}

void Game::update()
{
    switch(this->player->getDirection())
    {
    case Direction::Up:
        if(this->player->getPositionY() >= 365)
        {
            this->player->move({0.0f, -2.0f});
        }
        break;
    case Direction::Down:
        if(this->player->getPositionY() <= 555)
        {
            this->player->move({0.0f, 2.0f});
        }
        break;
    case Direction::Left:
        this->player->move({-2.0f, 0.0f});
        break;
    case Direction::Right:
        this->player->move({2.0f, 0.0f});
        break;
    default:
        break;
    }
}

void Game::draw(RenderWindow& twindow)
{
    twindow.clear(Color::Cyan);
    twindow.draw(*this->grass);
    this->player->drawTo(twindow);
    twindow.display();
}

void Game::start()
{
    this->init();
    while(true)
    {
        this->events(*this->window, *this->event);
        this->input();
        this->update();
        this->draw(*this->window);
        Sleep(FRAME_DELAY);
    }
}
