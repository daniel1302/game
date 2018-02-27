#ifndef ARKANOID_GAME_H
#define ARKANOID_GAME_H

#include <memory>
#include <stack>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"

struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
};

class Game
{
public:
    Game(int windowWidth, int windowHeight, std::string title);

private:
    const float _dt = 1.0f / 60;
    sf::Clock _clock;
    std::shared_ptr<GameData> _gameData = std::make_shared<GameData>();

    void run();
};

#endif //ARKANOID_GAME_H
