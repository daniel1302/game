#ifndef ARKANOID_BOARD_H
#define ARKANOID_BOARD_H


#include <vector>
#include <memory>
#include <Game.h>
#include "Paddle.h"
#include "Ball.h"
#include "Block.h"

class Board
{
public:
    Board(std::shared_ptr<GameData> game);

    const sf::Sprite &getBackground();

    std::vector<Block> &getVisibleBlocks();
//    const Paddle &getPaddle() const;
//    const Ball &getBall() const;

private:
    void generateLevel();

private:
    std::shared_ptr<GameData> _game;

    std::vector<Block> _blocks;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Paddle> paddle;


    sf::Sprite _background;
};


#endif //ARKANOID_BOARD_H
