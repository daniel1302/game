#ifndef ARKANOID_SPLASHSTATE_H
#define ARKANOID_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


class SplashState : public State {
public:
    SplashState(std::shared_ptr<GameData> game);


    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);

    std::string_view getName();

private:
    sf::Clock _clock;
    sf::Sprite _sprite;

    std::shared_ptr<GameData> _gameData;

};


#endif //ARKANOID_SPLASHSTATE_H
