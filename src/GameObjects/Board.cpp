#include "Board.h"
#include "definitions.h"
#include <random>
#include <iostream>


Board::Board(std::shared_ptr<GameData> game)
: _game(game)
{
    game
            ->assets
            .loadTexture("game_background", GAME_BACKGROUND_FILEPATH);
    game
            ->assets
            .loadTexture("texture", TEXTURE_FILEPATH);


    _background = sf::Sprite(
            game->assets.getTexture("game_background")
    );


    _paddle = std::make_unique<Paddle>(
        game->assets.getTexture("texture"),
        sf::IntRect(0, 111, 161, 25)
    );
    _paddle->getSprite().setPosition(450, 700);

    _ball = std::make_unique<Ball>(
            game->assets.getTexture("texture"),
            sf::IntRect(0, 80, 24, 24)
    );
    _ball->getSprite().setPosition(500, 450);

    generateLevel();
}

//TODO(daniel): Move it to separated class
void Board::generateLevel()
{
    std::array<sf::IntRect, 8> blocks = {
            {
                    sf::IntRect{0, 0, 65, 33},
                    sf::IntRect{71, 0, 65, 33},
                    sf::IntRect{149, 0, 65, 33},
                    sf::IntRect{216, 0, 65, 33},

                    sf::IntRect{0, 40, 65, 33},
                    sf::IntRect{71, 40, 65, 33},
                    sf::IntRect{149, 40, 65, 33},
                    sf::IntRect{216, 40, 65, 33}
            }
    };



    std::random_device device;
    std::mt19937 engine{device()};
    std::uniform_int_distribution<uint32_t> dist(10, 14);


    uint32_t blocksPerLine;
    uint32_t rightOffset;


    for (uint32_t line=0; line<6; line++)
    {
        blocksPerLine = dist(engine);
        rightOffset = (SCREEN_WIDTH-(blocksPerLine * 68)) / 2;

        std::cout<<"Line: "<<line<<"blocks: "<<blocksPerLine<<std::endl<<std::flush;
        for(;blocksPerLine>0; blocksPerLine--)
        {
            _blocks.push_back(
                    Block(
                            _game->assets.getTexture("texture"),\
                            blocks.at(line%(blocks.size()-1)),
                            sf::Vector2f(SCREEN_WIDTH-rightOffset-(blocksPerLine*68.0f), 20 + (line*33))
                    )
            );
        }
    }
}

void Board::update(float dt)
{
    static int disabledCollisionCounter = 0;
    if (disabledCollisionCounter++ % 5 == 0)
    {
        _ball->enableCollisions();
        disabledCollisionCounter = 0;
    }


    if (!_startedGame)
    {
        return;
    }


    _paddle->update(dt);
    _ball->update(dt);
    if (collisionChecker.check(
            _ball->getSprite(),
            _paddle->getSprite()
    )) {
        _ball->paddleCollision();
    }


    sf::Vector2f ballPosition = _ball->getSprite().getPosition();
    sf::FloatRect ballSize = _ball->getSprite().getLocalBounds();

    if (ballPosition.x <= 0)
    {
        _ball->borderCollision(Ball::Border::Left);
    }

    if (ballPosition.x > SCREEN_WIDTH - ballSize.width)
    {
        _ball->borderCollision(Ball::Border::Left);
    }

    if (ballPosition.y <= 0)
    {
        _ball->borderCollision(Ball::Border::Top);
    }

    for (auto &block : _blocks)
    {
        if (block.isHidden())
        {
            continue;
        }


        if (collisionChecker.check(
                _ball->getSprite(),
                block.getSprite()
        )) {
            _ball->blockCollision(block);
            _game->points += 10;
        }
    }

}

void Board::startGame()
{
    _startedGame = true;
}

const sf::Sprite& Board::getBackground()
{
    return _background;
}

std::vector<Block>& Board::getBlocks()
{
    return _blocks;
}

const sf::Sprite& Board::getPaddle()
{
    return _paddle->getSprite();
}

const sf::Sprite& Board::getBall()
{
    return _ball->getSprite();
}

void Board::movePaddle(Paddle::Direction direction)
{
    _paddle->accelerate(direction);
}

void Board::stopPaddle()
{
    _paddle->stop();
}