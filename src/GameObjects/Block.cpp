#include "Block.h"

Block::Block(
        sf::Texture &texture,
        const sf::IntRect &rect,
        const sf::Vector2f &position
)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(rect);
    _sprite.setPosition(position);
}


sf::Sprite& Block::getSprite()
{
    return _sprite;
}