#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H


#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball(const sf::Texture &texture, const sf::IntRect textureRect);
    sf::Sprite &getSprite() override;

private:
    sf::Sprite _sprite;
};


#endif //ARKANOID_BALL_H
