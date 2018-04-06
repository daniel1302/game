#include "SpriteCollision.h"

bool SpriteCollision::check(const sf::Sprite &sprite1, const sf::Sprite &sprite2)
{
    sf::FloatRect rect1 = sprite1.getGlobalBounds();
    sf::FloatRect rect2 = sprite2.getGlobalBounds();

    return rect1.intersects(rect2);
}