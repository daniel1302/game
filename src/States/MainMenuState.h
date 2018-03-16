#ifndef ARKANOID_MAINMENUSTATE_H
#define ARKANOID_MAINMENUSTATE_H

#include <memory>
#include <GameObjects/GameText.h>
#include <EventHandler.h>
#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
public:
    MainMenuState(std::shared_ptr<GameData> game);


    void init();
    void handleInput();
    void update(float dt);
    void draw(float dt);

private:
    std::shared_ptr<GameData> _gameData;

    sf::Sprite _background;
    sf::Text text;

    std::unique_ptr<GameText> _titleText;
    std::unique_ptr<GameText> _newGameText;
    std::unique_ptr<GameText> _authorsText;
    std::unique_ptr<GameText> _highscoresText;
    std::unique_ptr<GameText> _quitText;

    std::unique_ptr<EventHandler> _eventHandler;
};


#endif //ARKANOID_MAINMENUSTATE_H
