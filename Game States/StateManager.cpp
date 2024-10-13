//
// Created by Chandler Desforges on 6/8/24.
//

#include "StateManager.h"

#include <utility>

StateManager::StateManager() :
m_states()
{

}

void StateManager::pushState(StatePtr state)
{
    m_states.push(std::move(state));
}

void StateManager::popState()
{
    if(!m_states.empty())
        m_states.pop();
}

void StateManager::replaceState(StatePtr state)
{
    popState();
    pushState(std::move(state));
}

StatePtr StateManager::getCurrentState()
{
    if(!m_states.empty())
        return m_states.top();

    return nullptr;
}
