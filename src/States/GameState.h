#ifndef ARKANOID_GAMESTATE_H
#define ARKANOID_GAMESTATE_H


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

};

#endif //ARKANOID_GAMESTATE_H
