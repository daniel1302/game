#include "MainMenuState.h"
#include "Math/ImageAdjuster.h"
#include <iostream>
#include "definitions.h"


MainMenuState::MainMenuState(std::shared_ptr<GameData> game)
{
    _gameData = game;
}

void MainMenuState::init()
{
    _gameData
            ->assets
            .loadTexture("background", BACKGROUND_FILEPATH);

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

    _gameData
            ->assets
            .loadFont("arcade-classic", ARCADE_CLASSIC_FONT_FILEPATH);



    _titleText = std::make_unique<GameText>(
            "Arkanoid",
            _gameData->assets.getFont("arcade-classic"),
            88,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Align::Center,
            sf::Vector2f(0, 40)
    );

    _newGameText = std::make_unique<GameText>(
        "New game",
        _gameData->assets.getFont("arcade-classic"),
        52,
        sf::Color::White,
        sf::Text::Style::Regular,
        GameText::Center,
        sf::Vector2f(0, 200)
    );

    _highscoresText = std::make_unique<GameText>(
            "High scores",
            _gameData->assets.getFont("arcade-classic"),
            52,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Center,
            sf::Vector2f(0, 260)
    );

    _authorsText = std::make_unique<GameText>(
            "Authors",
            _gameData->assets.getFont("arcade-classic"),
            52,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Center,
            sf::Vector2f(0, 320)
    );

    _quitText = std::make_unique<GameText>(
            "Exit game",
            _gameData->assets.getFont("arcade-classic"),
            52,
            sf::Color::White,
            sf::Text::Style::Regular,
            GameText::Center,
            sf::Vector2f(0, 420)
    );

}

void MainMenuState::handleInput()
{
    sf::Event event;

    while (_gameData->window.pollEvent(event))
    {
        if (_gameData->input.isTextClicked(_newGameText->getText(), sf::Mouse::Left, _gameData->window)) {

            std::cout << "Go to New game state"<<std::flush;
            break;
        }

        if (_gameData->input.isTextClicked(_highscoresText->getText(), sf::Mouse::Left, _gameData->window)) {

            std::cout << "Go to High score"<<std::flush;
            break;
        }

        if (_gameData->input.isTextClicked(_authorsText->getText(), sf::Mouse::Left, _gameData->window)) {

            std::cout << "Go to New authors"<<std::flush;
            break;
        }

        if (event.type == sf::Event::Closed
                || _gameData->input.isTextClicked(_quitText->getText(), sf::Mouse::Left, _gameData->window)
        ) {

            _gameData->window.close();
        }

    }
}

void MainMenuState::update(float dt)
{

}

void MainMenuState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_background);

    _gameData->window.draw(_titleText->getText());
    _gameData->window.draw(_newGameText->getText());
    _gameData->window.draw(_highscoresText->getText());
    _gameData->window.draw(_authorsText->getText());
    _gameData->window.draw(_quitText->getText());



    _gameData->window.display();
}