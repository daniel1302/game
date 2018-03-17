#include <EventHandler.h>
#include "GameState.h"


GameState::GameState(std::shared_ptr<GameData> game)
:_game(game)
{
    _board = std::make_unique<Board>(game);
    _eventHandler = std::make_unique<EventHandler>(game);
}

void GameState::init()
{

}

void GameState::draw(float dt)
{
    _game->window.clear();

    _game->window.draw(_board->getBackground());

    for (auto& x : _board->getVisibleBlocks())
    {
        _game->window.draw(x.getSprite());
    }

    _game->window.display();
}

void GameState::handleInput()
{
    sf::Event event;

    while (_game->window.pollEvent(event))
    {
        _eventHandler->handleClose(event);
    }
}

void GameState::update(float dt)
{

}