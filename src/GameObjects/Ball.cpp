#include "Ball.h"

Ball::Ball(const sf::Texture &texture, const sf::IntRect textureRect)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(textureRect);
}

const sf::Sprite& Ball::getSprite() const
{
    return _sprite;
}