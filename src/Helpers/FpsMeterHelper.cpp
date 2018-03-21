#include <iostream>
#include "FpsMeterHelper.h"

FpsMeterHelper::FpsMeterHelper(std::shared_ptr<GameData> game)
:_game(game)
{
    _lastTime = _clock.getElapsedTime().asSeconds();

    std::string str = _prepareStrings(0.0);

    _text = std::make_unique<GameText>(
            str.c_str(),
            _game->assets.getFont("arcade-classic"),
            14,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Fixed,
            sf::Vector2f(10, 10)
    );
}

void FpsMeterHelper::update(float dt)
{
    float frameTime = _clock.getElapsedTime().asSeconds() - _lastTime;
    _lastTime = _clock.getElapsedTime().asSeconds();

    std::string str = _prepareStrings(1.0/frameTime);

    _text->getText().setString(str);
}

sf::Drawable& FpsMeterHelper::getItem()
{
    return static_cast<sf::Drawable&>(_text->getText());
}

std::string FpsMeterHelper::_prepareStrings(float frames)
{
    return std::string{"FPS " + std::to_string((int)frames)};
}