//
// Created by Chandler Desforges on 6/15/24.
//

#include "RandomAttackState.h"

RandomAttackState::RandomAttackState(AttackStateManager &attackStateManager, Player &playingAgainst,
                                     std::deque<Coordinates> &remainingTargets) :
                           AttackState(attackStateManager, playingAgainst, remainingTargets)
{}

void RandomAttackState::updateStack()
{
    if(!m_stackUpdated)
    {
        std::shuffle(m_remainingTargets.begin(), m_remainingTargets.end(), Rand::getRng());
        m_stackUpdated = true;
        std::cout << "Random attack state | updateStack ran\n";
    }
}

void RandomAttackState::attack()
{
    // make attack and save result
    auto result = m_playingAgainst.attack(m_remainingTargets.front());

    std::cout << "Random attack state | attacked: (" << toRow(result.coordinates.row) << ", " << result.coordinates.col << "), ship type: " << toString(result.shipType) << ", health:" << result.shipHealth << "\n";

    // remove attack from deque of possible targets
    if(!m_remainingTargets.empty())
        m_remainingTargets.pop_front();

    // if hit
    if(result.shipType != EMPTY)
    {
        m_stackUpdated = false;
        m_attackStateManager.pushState(std::make_shared<SearchState>(m_attackStateManager, m_playingAgainst, m_remainingTargets, result));
    }
}

std::string RandomAttackState::getType()
{
    return "random attack state";
}
