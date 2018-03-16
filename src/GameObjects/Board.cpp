#include "Board.h"
#include "definitions.h"



Board::Board(std::shared_ptr<GameData> game)
: _game(game)
{
    game
            ->assets
            .loadTexture("game_background", GAME_BACKGROUND_FILEPATH);


    _background = sf::Sprite(
            game->assets.getTexture("game_background")
    );
}

const sf::Sprite& Board::getBackground() const
{
    return _background;
}