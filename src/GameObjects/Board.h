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
    const int32_t paddleSpeed = 72;

    Board(std::shared_ptr<GameData> game);



    std::vector<Block> &getVisibleBlocks();
    const sf::Sprite &getPaddle();
    const sf::Sprite &getBall();
    const sf::Sprite &getBackground();

    void update(float dt);
    void movePaddle(Paddle::Direction direction);

private:
    void generateLevel();

private:
    std::shared_ptr<GameData> _game;

    std::vector<Block> _blocks;
    std::unique_ptr<Ball> _ball;
    std::unique_ptr<Paddle> _paddle;


    sf::Sprite _background;
};


#endif //ARKANOID_BOARD_H
