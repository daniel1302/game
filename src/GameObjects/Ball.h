#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H


#include "GameObject.h"
#include "Block.h"
#include "Paddle.h"
#include <memory>

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
    void blockCollision(Block &block);
    float randSpeed(float speed);
    void enableCollisions();
    bool isUnderPaddle(std::unique_ptr<Paddle> &paddle);

private:
    sf::Sprite _sprite;

    const float _speed = 400;
    const float _speedDistro = 0.4;

    sf::Vector2f _moveVector{0, 100};

    bool _collisionWait = false;
};


#endif //ARKANOID_BALL_H
