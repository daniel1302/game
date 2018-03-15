#ifndef ARKANOID_BLOCK_H
#define ARKANOID_BLOCK_H


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class Block : public GameObject {
public:
    const sf::Sprite &getSprite() const override;

private:
    sf::Sprite _sprite;
};


#endif //ARKANOID_BLOCK_H
