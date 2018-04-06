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


void Ball::paddleCollision()
{
    if (_moveVector.x > 0)
    {
        _moveVector.x = _speed;
    }
    else
    {
        _moveVector.x = -1 * _speed;
    }


    if (_moveVector.y > 0)
    {
        _moveVector.y = -1 * _speed;
    }
    else
    {
        _moveVector.y = _speed;
    }
}

void Ball::borderCollision()
{

}