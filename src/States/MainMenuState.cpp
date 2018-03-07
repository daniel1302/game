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

}

void MainMenuState::handleInput()
{
    sf::Event event;

    while (_gameData->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _gameData->window.close();
        }
    }
}

void MainMenuState::update(float dt)
{
    if (_gameData->input.isTextClicked(text, sf::Mouse::Left, _gameData->window))
    {
        std::cout<<"Clicked";
    }
}

void MainMenuState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_background);

    text.setFont(_gameData->assets.getFont("arcade-classic"));
    text.setString("Arkanoid");
    text.setCharacterSize(88);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,40));

    _gameData->window.draw(text);


    text.setCharacterSize(52);

    text.setString("New game");
    textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f, 200));

    _gameData->window.draw(text);


    text.setString("High scores");
    textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f, 260));

    _gameData->window.draw(text);


    text.setString("Authors");
    textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f, 320));

    _gameData->window.draw(text);


    text.setString("Exit game");
    textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
                   textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f, 440));

    _gameData->window.draw(text);



    _gameData->window.display();
}