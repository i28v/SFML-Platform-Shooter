#include "../include/Bullet.h"

Bullet::Bullet(Vector2f size, Vector2f position)
{
    this->bTexture = new Texture();
    this->bSprite = new Sprite();
    this->bTexture->loadFromMemory(bulletData, sizeof(bulletData));
    this->bSprite->setTexture(*this->bTexture);
    this->bSprite->setScale(size);
    this->bSprite->setPosition(position);
    this->bgunshot.loadFromMemory(gunshotData, sizeof(gunshotData));
    this->gunshot.setBuffer(this->bgunshot);
}

Bullet::~Bullet()
{
    delete[] this->bTexture;
    delete[] this->bSprite;
}

void Bullet::drawTo(RenderWindow& twindow)
{
    twindow.draw(*this->bSprite);
}

void Bullet::move(Vector2f direction)
{
    this->bSprite->move(direction);
}

void Bullet::setPosition(Vector2f position)
{
    this->bSprite->setPosition(position);
}

void Bullet::setRotation(float rotation)
{
    this->bSprite->setRotation(rotation);
}

void Bullet::playGunshot()
{
    this->gunshot.play();
}

Vector2f Bullet::getPosition()
{
    return this->bSprite->getPosition();
}

float Bullet::getPositionX()
{
    return this->bSprite->getPosition().x;
}

float Bullet::getPositionY()
{
    return this->bSprite->getPosition().y;
}
