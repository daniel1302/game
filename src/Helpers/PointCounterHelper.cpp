#include "PointCounterHelper.h"
#include "definitions.h"


PointCounterHelper::PointCounterHelper(std::shared_ptr<GameData> gameData)
{
    _gameData = gameData;

    std::string pointsStr{""};

    _text = std::make_unique<GameText>(
            pointsStr.c_str(),
            _gameData->assets.getFont("arcade-classic"),
            24,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Fixed,
            sf::Vector2f(900, 0)
    );

}

sf::Drawable& PointCounterHelper::getItem()
{
    return static_cast<sf::Drawable&>(_text->getText());
}

void PointCounterHelper::update(float dt)
{
    if (_gameData->machine.getCurrentState()->getName() == GAME_STATE_STR) {
        _text->getText().setString(std::to_string(static_cast<int>(_gameData->points)));

        return;
    }

    _text->getText().setString(std::string{""});
}