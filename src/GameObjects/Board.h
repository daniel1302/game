#ifndef ARKANOID_BOARD_H
#define ARKANOID_BOARD_H


#include <vector>
#include <memory>
#include "Paddle.h"
#include "Ball.h"

class Board
{
public:
    const std::vector &getVisibleBlocks() const;
    const Paddle &getPaddle() const;
    const Ball &getBall() const;


private:
    std::vector blocks;
    std::unique_ptr<Ball> ball;
    std::unique_ptr<Paddle> paddle;
};


#endif //ARKANOID_BOARD_H
