#ifndef ARKANOID_DRAWABLE_H
#define ARKANOID_DRAWABLE_H

#include <SFML/Graphics/Drawable.hpp>

class Drawable
{
public:
    virtual sf::Drawable &getItem() = 0;
    virtual void update(float dt) = 0;

    virtual ~Drawable() {};
};

#endif //ARKANOID_DRAWABLE_H
