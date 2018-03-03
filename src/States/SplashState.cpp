#include "SplashState.h"

#include <iostream>

SplashState::SplashState(std::shared_ptr<GameData> game)
{
    _gameData = game;
    std::cout<<"SplashState::SplashState()";
}

void SplashState::init()
{
//    _texture =
    std::cout<<"SplashState::init()";
}

void SplashState::handleInput()
{
    std::cout<<"SplashState::handleInput()";
}

void SplashState::update(float dt)
{
    std::cout<<"SplashState::update()";
}

void SplashState::draw(float dt)
{
    std::cout<<"SplashState::draw()";
}

