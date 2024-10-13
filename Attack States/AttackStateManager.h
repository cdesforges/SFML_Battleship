//
// Created by Chandler Desforges on 6/13/24.
//

#ifndef INC_06_LAB_BATTLESHIP_ATTACKSTATEMANAGER_H
#define INC_06_LAB_BATTLESHIP_ATTACKSTATEMANAGER_H

#include "AttackState.h"
#include <stack>

class AttackState;
using AttackStatePtr = std::shared_ptr<AttackState>;

class AttackStateManager
{
private:
    std::stack<AttackStatePtr> m_attackStates;

public:
    AttackStateManager();

    void pushState(AttackStatePtr state);
    void popState();
    void replaceState(AttackStatePtr state);
    AttackStatePtr getCurrentState();
};


#endif //INC_06_LAB_BATTLESHIP_ATTACKSTATEMANAGER_H
