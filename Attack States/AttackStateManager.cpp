//
// Created by Chandler Desforges on 6/13/24.
//

#include "AttackStateManager.h"

AttackStateManager::AttackStateManager() :
m_attackStates()
{}

void AttackStateManager::pushState(AttackStatePtr state)
{
    m_attackStates.push(std::move(state));
}

void AttackStateManager::popState()
{
    if(!m_attackStates.empty())
        m_attackStates.pop();
}

void AttackStateManager::replaceState(AttackStatePtr state)
{
    popState();
    pushState(std::move(state));
}

AttackStatePtr AttackStateManager::getCurrentState()
{
    if(!m_attackStates.empty())
        return m_attackStates.top();

    return nullptr;
}
