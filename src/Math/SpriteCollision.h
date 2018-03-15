#ifndef ARKANOID_SPRITECOLLISION_H
#define ARKANOID_SPRITECOLLISION_H


#include <SFML/Graphics/Sprite.hpp>

class SpriteCollision
{
public:
    bool check(const sf::Sprite &sprite1, const sf::Sprite &sprite2);

private:
};


#endif //ARKANOID_SPRITECOLLISION_H
