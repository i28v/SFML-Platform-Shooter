#include "../include/Player.h"

Player::Player(Vector2f size, Vector2f position)
{
    this->pTexture = new Texture();
    this->pSprite = new Sprite();
    this->pTexture->loadFromMemory(playerData, sizeof(playerData));
    this->pSprite->setTexture(*this->pTexture);
    this->pSprite->setScale(size);
    this->pSprite->setPosition(position);
}

Player::~Player()
{
    delete[] this->pTexture;
    delete[] this->pSprite;
}

void Player::drawTo(RenderWindow& twindow)
{
    twindow.draw(*this->pSprite);
}

void Player::setDirection(Direction dir)
{
    this->pDir = dir;
}

void Player::move(Vector2f direction)
{
    this->pSprite->move(direction);
}

Vector2f Player::getPosition()
{
    return this->pSprite->getPosition();
}

float Player::getPositionX()
{
    return this->pSprite->getPosition().x;
}

float Player::getPositionY()
{
    return this->pSprite->getPosition().y;
}

Direction Player::getDirection()
{
    return this->pDir;
}
