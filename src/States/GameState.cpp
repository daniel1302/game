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
    _game->window.draw(_board->getBackground());
    _game->window.draw(_board->getPaddle());
    _game->window.draw(_board->getBall());

    for (auto& x : _board->getVisibleBlocks())
    {
        _game->window.draw(x.getSprite());
    }
}

void GameState::handleInput()
{
    sf::Event event;


    while (_game->window.pollEvent(event))
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            _board->movePaddle(Paddle::Left);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            _board->movePaddle(Paddle::Right);
        }

        _eventHandler->handleClose(event);
    }
}

void GameState::update(float dt)
{

}