#ifndef ARKANOID_MAINMENUSTATE_H
#define ARKANOID_MAINMENUSTATE_H

#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
public:
    MainMenuState(std::shared_ptr<GameData> game);


    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    std::shared_ptr<GameData> _gameData;

    sf::Sprite _sprite;
};


#endif //ARKANOID_MAINMENUSTATE_H
