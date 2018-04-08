#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H


#include "GameObject.h"

class Ball : public GameObject
{
public:
    enum Border
    {
        Top,
        Left,
        Right,
        Down
    };


public:
    Ball(const sf::Texture &texture, const sf::IntRect& textureRect);
    sf::Sprite &getSprite() override;
    void update(float dt) override;

    void paddleCollision();
    void borderCollision(Border border);
    float randSpeed(float speed);


private:
    sf::Sprite _sprite;

    const float _speed = 400;
    const float _speedDistro = 0.2;

    sf::Vector2f _moveVector{0, 100};
};


#endif //ARKANOID_BALL_H
