#ifndef ARKANOID_GAMEOBJECT_H
#define ARKANOID_GAMEOBJECT_H


#include <SFML/Graphics/Sprite.hpp>

class GameObject {
public:
    virtual const sf::Sprite &getSprite() const = 0;
    virtual ~GameObject() {};
};


#endif //ARKANOID_GAMEOBJECT_H
