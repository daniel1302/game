#ifndef ARKANOID_GAMEOBJECT_H
#define ARKANOID_GAMEOBJECT_H


#include <SFML/Graphics/Sprite.hpp>

class GameObject {
public:
    virtual void update(float dt) = 0;
    virtual sf::Sprite &getSprite() = 0;
    virtual ~GameObject() {};
};


#endif //ARKANOID_GAMEOBJECT_H
