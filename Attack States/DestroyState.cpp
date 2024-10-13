//
// Created by Chandler Desforges on 6/15/24.
//

#include "DestroyState.h"

DestroyState::DestroyState(AttackStateManager &attackStateManager, Player &playingAgainst,
                           std::deque<Coordinates> &remainingTargets, const HitResult &anchorHit,
                           const HitResult &secondHit) :
AttackState{attackStateManager, playingAgainst, remainingTargets}
{
//    std::cout << "Destroy state | initializing\n";
    m_anchorHit = anchorHit;
    m_secondHit = secondHit;

    m_direction.row = m_secondHit.coordinates.row - m_anchorHit.coordinates.row;
    m_direction.col = m_secondHit.coordinates.col - m_anchorHit.coordinates.col;
}

void DestroyState::updateStack()
{
    if(!m_stackUpdated)
    {
        std::cout << "Destroy state | stack update ran";
        std::cout << "Destroy state | Anchor hit: " << toRow(m_anchorHit.coordinates.row) << ", " << m_anchorHit.coordinates.col << std::endl;
        std::cout << "Destroy state | Second hit: " << toRow(m_secondHit.coordinates.row) << ", " << m_secondHit.coordinates.col << std::endl;

        for(int i = 3; i > 0; i--)
        {
            std::cout << "Destroy state | Ship health: " << m_secondHit.shipHealth << std::endl;
            std::cout << "Destroy state | About to find and move to front: " << toRow((m_secondHit.coordinates + (m_direction * i)).row) << ", " << (m_secondHit.coordinates + (m_direction * i)).col << std::endl;
            findAndMoveToFront(m_secondHit.coordinates + (m_direction * i));
        }

        m_stackUpdated = true;
    }
}

void DestroyState::attack()
{
    // attack and save result
    auto result = m_playingAgainst.attack(m_remainingTargets.front());

    std::cout << "Destroy state | attacked: (" << toRow(result.coordinates.row) << ", " << result.coordinates.col << "), ship type: " << toString(result.shipType) << ", health:" << result.shipHealth << "\n";

    // remove attack from deque of possible targets
    if(!m_remainingTargets.empty())
            m_remainingTargets.pop_front();

    // if sunk
    if(result.shipHealth == 0)
        m_attackStateManager.popState();

    // if miss
    if(result.shipType == EMPTY)
        m_attackStateManager.replaceState(std::make_shared<DestroyState>(m_attackStateManager, m_playingAgainst,
                                                                         m_remainingTargets, m_secondHit, m_anchorHit));

    // if hit another ship
    if(result.shipType != EMPTY && result.shipType != m_anchorHit.shipType)
    {
        m_attackStateManager.replaceState(std::make_shared<DestroyState>(m_attackStateManager, m_playingAgainst,
                                                                         m_remainingTargets, m_secondHit,
                                                                         m_anchorHit));
        m_attackStateManager.pushState(std::make_shared<SearchState>(m_attackStateManager, m_playingAgainst,
                                                                     m_remainingTargets, result));
    }
}

std::string DestroyState::getType()
{
    return "destroy state";
}
