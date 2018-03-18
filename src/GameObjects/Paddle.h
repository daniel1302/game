#ifndef ARKANOID_PADDLE_H
#define ARKANOID_PADDLE_H


#include "GameObject.h"

class Paddle : public GameObject
{
public:
    enum Direction
    {
        Left,
        Right
    };

    Paddle(const sf::Texture &texture, const sf::IntRect& textureRect);
    sf::Sprite &getSprite() override;

private:
    sf::Sprite _sprite;
};


#endif //ARKANOID_PADDLE_H
