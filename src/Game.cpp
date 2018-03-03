#include "Game.h"
#include "States/SplashState.h"

Game::Game(
        int windowWidth,
        int windowHeight,
        std::string title
) {
    _gameData->window.create(
            sf::VideoMode(windowWidth, windowHeight),
            title,
            sf::Style::Close | sf::Style::Titlebar
    );

    _gameData->machine.addState(std::make_unique<SplashState>(_gameData));

    this->run();
}

void Game::run()
{
    float newTime, frameTime, interpolation;

    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while( this->_gameData->window.isOpen())
    {
        this->_gameData->machine.processStateChanges();

        newTime = this->_clock.getElapsedTime().asSeconds();

        frameTime = newTime - currentTime;

        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= _dt)
        {
            this
                    ->_gameData
                    ->machine
                    .getCurrentState()
                    ->handleInput();

            this
                    ->_gameData
                    ->machine
                    .getCurrentState()
                    ->update(_dt);

            accumulator -= _dt;
        }

        interpolation = accumulator / _dt;
        this
                ->_gameData
                ->machine
                .getCurrentState()
                ->draw(interpolation);
    }
}