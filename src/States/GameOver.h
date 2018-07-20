#ifndef ARKANOID_SPLASHSTATE_H
#define ARKANOID_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "EventHandler.h"
#include "GameObjects/GameText.h"
#include "Math/ImageAdjuster.h"


class GameOver : public State {
public:
    GameOver(std::shared_ptr<GameData> game);
    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);
    std::string_view getName();

private:
    std::shared_ptr<GameData> _gameData;
    std::unique_ptr<EventHandler> _eventHandler;

    sf::Sprite _background;
    sf::Text text;

    std::unique_ptr<GameText> _gameOverText;
    std::unique_ptr<GameText> _infoText;
};


#endif //ARKANOID_SPLASHSTATE_H
