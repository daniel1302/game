#ifndef ARKANOID_INPUTMANAGER_H
#define ARKANOID_INPUTMANAGER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class InputManager
{
public:
    InputManager() {}
    ~InputManager() {}

    bool isSpriteClicked(
            sf::Sprite object,
            sf::Mouse::Button button,
            sf::RenderWindow &window
    );

    sf::Vector2i getMousePosition(sf::RenderWindow &window);
};

#endif //ARKANOID_INPUTMANAGER_H
