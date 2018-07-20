#include <random>
#include "Ball.h"

Ball::Ball(const sf::Texture &texture, const sf::IntRect& textureRect)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(textureRect);
}

sf::Sprite& Ball::getSprite()
{
    return _sprite;
}

void Ball::update(float dt)
{
    sf::Vector2f currentPosition = _sprite.getPosition();

    _sprite.setPosition(
            currentPosition.x + (_moveVector.x * dt),
            currentPosition.y + (_moveVector.y * dt)
    );
}

void Ball::enableCollisions()
{
    _collisionWait = false;
}


void Ball::paddleCollision()
{
    if (_collisionWait == true)
    {
        return;
    }

    if (_moveVector.x > 0)
    {
        _moveVector.x = randSpeed(_speed);
    }
    else
    {
        _moveVector.x = -1 * randSpeed(_speed);
    }


    if (_moveVector.y > 0)
    {
        _moveVector.y = -1 * randSpeed(_speed);
    }
    else
    {
        _moveVector.y = randSpeed(_speed);
    }

    _collisionWait = true;
}

void Ball::borderCollision(Border border)
{
    if (_collisionWait == true)
    {
        return;
    }

    if (_moveVector.x < 0)
    {
        _moveVector.x = randSpeed(_speed);
    }
    else
    {
        _moveVector.x = -1 * randSpeed(_speed);
    }

    if (border == Border::Top)
    {
        _moveVector.y = (_moveVector.y < 0)
                ? randSpeed(_speed)
                : -1 * randSpeed(_speed);


        _moveVector.x = (_moveVector.x < 0)
                ? randSpeed(_speed)
                : -1 * randSpeed(_speed);
    }

    _collisionWait = true;
}

void Ball::blockCollision(Block &block)
{
    block.hide();
    _moveVector.x *= -1.0;
    _moveVector.y *= -1.0;
}

float Ball::randSpeed(float speed)
{
    auto minSpeed = static_cast<int>(speed - speed * _speedDistro);
    auto maxSpeed = static_cast<int>(speed + speed * _speedDistro);

    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<> dist(minSpeed, maxSpeed);

    return dist(engine);
}

bool Ball::isUnderPaddle(std::unique_ptr<Paddle> &paddle)
{
    sf::Vector2f currentPosition = _sprite.getPosition();

    if (currentPosition.y > paddle->getSprite().getPosition().y) {
        return true;
    }

    return false;
}