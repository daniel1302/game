#ifndef ARKANOID_POINTCOUNTERHELPER_H
#define ARKANOID_POINTCOUNTERHELPER_H


#include <memory>
#include <Game.h>
#include <GameObjects/GameText.h>
#include "Drawable.h"


class PointCounterHelper : public Drawable {

public:
    PointCounterHelper(std::shared_ptr<GameData> game);
    sf::Drawable &getItem();
    void update(float dt);


private:
    std::shared_ptr<GameData> _gameData;
    std::unique_ptr<GameText> _text;

};


#endif //ARKANOID_POINTCOUNTERHELPER_H
