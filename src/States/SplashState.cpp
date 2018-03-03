#include "SplashState.h"
#include "definitions.h"

#include <iostream>

SplashState::SplashState(std::shared_ptr<GameData> game)
{
    _gameData = game;
}

void SplashState::init()
{
    _gameData
            ->assets
            .loadTexture("splash_state_background", SPLASH_STATE_BACKGROUND_FILEPATH);

    _sprite.setTexture(_gameData
                   ->assets
                   .getTexture("splash_state_background")
    );


    sf::Vector2u textureSize = _sprite
            .getTexture()
            ->getSize();


    sf::Vector2f textureScale(1, 1);

    /**
     * Screen.x > screen.y
     *      img x > img.y
     *
     */
    if (textureSize.x > SCREEN_WIDTH || textureSize.y > SCREEN_HEIGHT)
    {


        _sprite.scale(textureScale);
    }


    sf::Vector2f texturePosition(0, 0);

    if (textureSize.x < SCREEN_WIDTH)
    {
        texturePosition.x = (SCREEN_WIDTH-textureSize.x)/2;
    }

    if (textureSize.y < SCREEN_HEIGHT)
    {
        texturePosition.y = (SCREEN_HEIGHT-textureSize.y)/2;
    }

    _sprite.setPosition(texturePosition);

}

void SplashState::handleInput()
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

void SplashState::update(float dt)
{

}

void SplashState::draw(float dt)
{
    _gameData->window.clear();

    _gameData->window.draw(_sprite);

    _gameData->window.display();
}

