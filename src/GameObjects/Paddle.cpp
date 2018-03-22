#include <iostream>
#include "Paddle.h"
#include "definitions.h"


Paddle::Paddle(const sf::Texture &texture, const sf::IntRect& textureRect)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(textureRect);
}

sf::Sprite& Paddle::getSprite()
{
    return _sprite;
}

void Paddle::update(float dt)
{
    if (_speed > 0)
    {
        _speed -= ((_maxSpeed - _speed) / _maxSpeed)*_acceleration*dt;
    }

    if (_speed <= 0)
    {
        _speed = 0;

        return;
    }

    int maxPosition = SCREEN_WIDTH - _sprite.getGlobalBounds().width;
    if (_sprite.getPosition().x < 0)
    {
        _speed = 0;
        _sprite.setPosition(0, _sprite.getPosition().y);

        return;
    }
    else if(_sprite.getPosition().x  > maxPosition)
    {
        _speed = 0;
        _sprite.setPosition(maxPosition, _sprite.getPosition().y);

        return;
    }

    float movement = _speed*dt/1000;



    if (_direction == Direction::Left)
    {
        movement *= -1;
    }

    _sprite.setPosition(
            _sprite.getPosition().x + movement,
            _sprite.getPosition().y
    );
}

void Paddle::accelerate(Direction direction)
{
    _direction = direction;

    if (_speed >= _maxSpeed)
    {
        _speed = _maxSpeed;
        return;
    }
    _speed = _speed + ((_maxSpeed - _speed) / _maxSpeed) * _acceleration;
}