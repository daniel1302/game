#ifndef ARKANOID_PADDLE_H
#define ARKANOID_PADDLE_H


#include <SFML/System/Clock.hpp>
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
    void update(float dt) override;
    void accelerate(Direction direction);
    void stop();

private:
    sf::Sprite _sprite;
    sf::Clock _clock;

    float lastAcceleration;

    const float _maxSpeed = 360000;
    float _acceleration = 144000.0;
    float _speed = 0;
    Direction _direction = Direction::Right;
};


#endif //ARKANOID_PADDLE_H
