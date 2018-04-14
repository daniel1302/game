#include "SplashState.h"
#include "definitions.h"

#include "Math/ImageAdjuster.h"
#include "MainMenuState.h"


SplashState::SplashState(std::shared_ptr<GameData> game)
{
    _gameData = game;
}

std::string_view SplashState::getName()
{
    return std::string_view(SPLASH_STATE_STR);
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


    sf::Vector2u _textureSize = _sprite
            .getTexture()
            ->getSize();

    sf::Vector2f textureSize(_textureSize.x, _textureSize.y);

    ImageAdjuster adjuster = ImageAdjuster(
            sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT),
            textureSize
    );

    sf::Vector2f textureScale = adjuster.scale(false);
    textureSize.x *= textureScale.x;
    textureSize.y *= textureScale.y;
    _sprite.scale(textureScale);

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
    if (_clock.getElapsedTime().asMilliseconds() > SPLASH_SCREEN_DURATION_MS)
    {
        _gameData->machine.addState(std::make_unique<MainMenuState>(_gameData));
    }
}

void SplashState::draw(float dt)
{
    _gameData->window.draw(_sprite);
}

