#include "GameOver.h"
#include "definitions.h"


GameOver::GameOver(std::shared_ptr<GameData> game)
{
    _gameData = game;
    _eventHandler = std::make_unique<EventHandler>(game);


}

void GameOver::init()
{
    _background.setTexture(_gameData
                                   ->assets
                                   .getTexture("background")
    );
    ImageAdjuster adjuster(
            sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
            sf::Vector2f(_background.getTexture()->getSize())
    );

    sf::Vector2f scale = adjuster.scale(true);

    _background.scale(scale);

    _gameOverText = std::make_unique<GameText>(
            "Game Over",
            _gameData->assets.getFont("arcade-classic"),
            122,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Align::Center,
            sf::Vector2f(0,140)
    );

    _infoText = std::make_unique<GameText>(
            "Press ESC to back to the main menu",
            _gameData->assets.getFont("arcade-classic"),
            40,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Align::Center,
            sf::Vector2f(0, 290)
    );
}

void GameOver::draw(float dt)
{
    _gameData->window.draw(_background);

    _gameData->window.draw(_gameOverText->getText());
    _gameData->window.draw(_infoText->getText());
}

void GameOver::handleInput()
{
    sf::Event event;


    while (_gameData->window.pollEvent(event))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            _gameData->machine.removeState();
        }

        _eventHandler->handleClose(event);
    }
}

void GameOver::update(float dt)
{

}

std::string_view GameOver::getName()
{
    return std::string_view(GAME_OVER_STATE_STR);
}