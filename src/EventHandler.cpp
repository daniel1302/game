#include "EventHandler.h"


EventHandler::EventHandler(std::shared_ptr<GameData> game)
: _game(game)
{

}

void EventHandler::handleClose(const sf::Event &event, bool additionalCondition)
{
    if (event.type == sf::Event::Closed || additionalCondition) {
        _game->window.close();
    }
}