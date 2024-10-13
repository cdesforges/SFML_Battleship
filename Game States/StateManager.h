//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_STATEMANAGER_H
#define INC_06_LAB_BATTLESHIP_STATEMANAGER_H

#include <stack>
#include <memory>
#include "State.h"

class StateManager
{
private:
    std::stack<StatePtr> m_states;

public:
    StateManager();

    void pushState(StatePtr state);
    void popState();
    void replaceState(StatePtr state);
    StatePtr getCurrentState();
};


#endif //INC_06_LAB_BATTLESHIP_STATEMANAGER_H
