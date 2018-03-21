#ifndef ARKANOID_DEBUGHELPER_H
#define ARKANOID_DEBUGHELPER_H


#include <SFML/System/Clock.hpp>
#include <memory>
#include "GameObjects/GameText.h"
#include "Drawable.h"
#include "Game.h"

class FpsMeterHelper : public Drawable
{
public:
    FpsMeterHelper(std::shared_ptr<GameData> game);

    sf::Drawable& getItem();
    void update(float dt);


private:
    std::string _prepareStrings(float frames);

private:
    std::shared_ptr<GameData> _game;
    std::unique_ptr<GameText> _text;

    sf::Clock _clock;
    float _lastTime;
};


#endif //ARKANOID_DEBUGHELPER_H
