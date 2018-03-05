#include "MainMenuState.h"
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
            .loadTexture("texture", TEXTURE_FILEPATH);

    _sprite.setTexture(_gameData
                               ->assets
                               .getTexture("splash_state_background")
    );
    std::cout<<"MainMenuState::init(): "<<_gameData.get() <<std::endl<<std::flush;
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

}

void MainMenuState::draw(float dt)
{
//    std::cout<<"MainMenuState::draw()"<<std::endl<<std::flush;
//    _gameData->window.draw(_sprite);

    _gameData->window.clear();
    _gameData->window.display();
}