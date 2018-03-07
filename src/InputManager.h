#ifndef ARKANOID_INPUTMANAGER_H
#define ARKANOID_INPUTMANAGER_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

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

    bool isTextClicked(
            sf::Text object,
            sf::Mouse::Button button,
            sf::RenderWindow &window
    );

    sf::Vector2i getMousePosition(sf::RenderWindow &window);

protected:
    bool isClicked(
            const sf::Vector2f &position,
            const sf::FloatRect &bound,
            const sf::Mouse::Button button,
            const sf::RenderWindow &window
    );
};

#endif //ARKANOID_INPUTMANAGER_H
