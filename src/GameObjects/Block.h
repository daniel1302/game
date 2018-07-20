#ifndef ARKANOID_BLOCK_H
#define ARKANOID_BLOCK_H


#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "GameObject.h"

class Block : public GameObject {
public:
    Block(
            sf::Texture &texture,
            const sf::IntRect &rect,
            const sf::Vector2f &position = sf::Vector2f(0,0)
    );
    sf::Sprite &getSprite() override;
    void update(float dt) override;
    void hide();
    bool isHidden();

private:
    sf::Sprite _sprite{};

    bool _hidden = false;
};


#endif //ARKANOID_BLOCK_H
