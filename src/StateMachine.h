#ifndef ARKANOID_STATEMACHINE_H
#define ARKANOID_STATEMACHINE_H

#include <memory>
#include <stack>
#include "State.h"

class StateMachine
{
public:
    StateMachine() {}
    ~StateMachine() {}

    void addState(std::unique_ptr<State> newState, bool isReplacing = true);
    void removeState();

    void processStateChanges();
    std::unique_ptr<State> &getCurrentState();

private:
    std::stack<std::unique_ptr<State>> _states;
    std::unique_ptr<State> _newState;

    bool _isAdding;
    bool _isReplacing;
    bool _isRemoving;

};

#endif //ARKANOID_STATEMACHINE_H
