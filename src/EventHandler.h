#ifndef ARKANOID_EVENTHANDLER_H
#define ARKANOID_EVENTHANDLER_H


#include "Game.h"
#include <bits/shared_ptr.h>
#include <SFML/Window/Event.hpp>

class EventHandler
{
public:
    EventHandler(std::shared_ptr<GameData> game);
    void handleClose(
            const sf::Event &event,
            bool additionalCondition=false
    );

private:
    std::shared_ptr<GameData> _game;
};


#endif //ARKANOID_EVENTHANDLER_H
