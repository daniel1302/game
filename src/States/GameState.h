#ifndef ARKANOID_GAMESTATE_H
#define ARKANOID_GAMESTATE_H


#include "GameObjects/Board.h"
#include <memory>
#include "Game.h"


class GameState : public State
{
public:
    GameState(std::shared_ptr<GameData> game);


    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    std::shared_ptr<GameData> _game;
    std::unique_ptr<Board> _board;

    std::unique_ptr<EventHandler> _eventHandler;

};

#endif //ARKANOID_GAMESTATE_H
