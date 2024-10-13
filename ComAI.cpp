//
// Created by Chandler Desforges on 6/9/24.
//

#include "ComAI.h"

ComAI::ComAI(Player& playingAgainst) :
m_playingAgainst(playingAgainst)
{
    m_attackStateManager.pushState(std::make_shared<RandomAttackState>(m_attackStateManager, m_playingAgainst, m_remainingTargets));
    initializeMoveStack();
}

Row ComAI::toRow(int rowIndex)
{
    switch(rowIndex)
    {
        case 0:
            return A;
        case 1:
            return B;
        case 2:
            return C;
        case 3:
            return D;
        case 4:
            return E;
        case 5:
            return F;
        case 6:
            return G;
        case 7:
            return H;
        case 8:
            return I;
        case 9:
            return J;
        default:
            return INIT_ROW;
    }
}

void ComAI::attack()
{
    m_attackStateManager.getCurrentState()->updateStack();
    m_attackStateManager.getCurrentState()->attack();
}

void ComAI::initializeMoveStack()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            m_remainingTargets.emplace_front(toRow(i), j);
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(m_remainingTargets.begin(), m_remainingTargets.end(), g);
}