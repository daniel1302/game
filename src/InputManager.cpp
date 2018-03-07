#include "InputManager.h"

bool InputManager::isClicked(
        const sf::Vector2f &position,
        const sf::FloatRect &bound,
        const sf::Mouse::Button button,
        const sf::RenderWindow &window
)
{
    if (sf::Mouse::isButtonPressed(button))
    {
        sf::IntRect tempRect(
                position.x,
                position.y,
                bound.width,
                bound.height
        );

        if (tempRect.contains(sf::Mouse::getPosition(window)))
        {
            return true;
        }
    }

    return false;
}

bool InputManager::isSpriteClicked(
        sf::Sprite object,
        sf::Mouse::Button button,
        sf::RenderWindow &window
)
{
    return this->isClicked(
            object.getPosition(),
            object.getGlobalBounds(),
            button,
            window
    );
}


bool InputManager::isTextClicked(
        sf::Text object,
        sf::Mouse::Button button,
        sf::RenderWindow &window
)
{
    return this->isClicked(
            sf::Vector2f(object.getGlobalBounds().left, object.getGlobalBounds().top),
            object.getGlobalBounds(),
            button,
            window
    );
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window);
}