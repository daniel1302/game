#include "Paddle.h"


Paddle::Paddle(const sf::Texture &texture, const sf::IntRect& textureRect)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(textureRect);
}

sf::Sprite& Paddle::getSprite()
{
    return _sprite;
}