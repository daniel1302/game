#ifndef ARKANOID_STATE_H
#define ARKANOID_STATE_H

class State
{
public:
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(float dt) = 0;

    virtual void pause() { };
    virtual void resume() { };


    virtual ~State() { }
};

#endif //ARKANOID_STATE_H
