#include "Board.h"
#include "definitions.h"
#include <random>


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
    std::uniform_int_distribution<uint32_t> dist(10, 18);


    uint32_t blocksPerLine;
    uint32_t rightOffset;


    for (uint32_t line=0; line<6; line++)
    {
        blocksPerLine = dist(engine);
        rightOffset = (SCREEN_WIDTH-(blocksPerLine * 68)) / 2;

        for(;blocksPerLine>0; blocksPerLine--)
        {
            _blocks.push_back(
                    Block(_game->assets.getTexture("texture"),
                    blocks.at(blocksPerLine%6),
                    sf::Vector2f(SCREEN_WIDTH-rightOffset-(blocksPerLine*68), 20 + (line*33))
                    )
            );
        }
    }
}

const sf::Sprite& Board::getBackground()
{
    return _background;
}

std::vector<Block>& Board::getVisibleBlocks()
{
    return _blocks;
}