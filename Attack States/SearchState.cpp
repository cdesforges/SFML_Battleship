//
// Created by Chandler Desforges on 6/13/24.
//

#include "SearchState.h"

SearchState::SearchState(AttackStateManager& attackStateManager, Player& playingAgainst, std::deque<Coordinates>& remainingTargets, const HitResult& anchorHit) :
AttackState{attackStateManager, playingAgainst, remainingTargets}
{
    m_anchorHit = anchorHit;
}

void SearchState::updateStack()
{
    if(!m_stackUpdated)
    {
        std::cout << "Search state | updateStack ran\n";
        newDirections();

        // add NSEW to top of the stack
        while(!m_directions.empty())
        {
            std::cout << "Search state | Anchor hit: " << toRow(m_anchorHit.coordinates.row) << ", " << m_anchorHit.coordinates.col << std::endl;
            std::cout << "Search state | About to find and move to front: " << toRow((m_anchorHit.coordinates + m_directions.top()).row) << ", " << (m_anchorHit.coordinates + m_directions.top()).col << std::endl;
            findAndMoveToFront(m_anchorHit.coordinates + m_directions.top());
            m_directions.pop();
        }

        m_stackUpdated = true;
    }
}

void SearchState::attack()
{
    // attack and save result!
    auto result = m_playingAgainst.attack(m_remainingTargets.front());

    std::cout << "Search state state | attacked: (" << toRow(result.coordinates.row) << ", " << result.coordinates.col << "), ship type: " << toString(result.shipType) << ", health: " << result.shipHealth << "\n";


    // remove attack from deque of possible targets
    if(!m_remainingTargets.empty())
        m_remainingTargets.pop_front();

    // if we sunk a ship
    if(result.shipHealth == 0)
        m_attackStateManager.replaceState(std::make_shared<RandomAttackState>(m_attackStateManager, m_playingAgainst, m_remainingTargets));

    // if we hit the same ship
    if(result.shipHealth != 0 && result.shipType == m_anchorHit.shipType)
    {
        m_attackStateManager.replaceState(std::make_shared<DestroyState>(m_attackStateManager, m_playingAgainst, m_remainingTargets, m_anchorHit, result));
        std::cout << "Search state | replaced with DestroyState\n";
    }

    // if we hit a different ship
    else if(result.shipType != EMPTY && result.shipType != m_anchorHit.shipType)
    {
        m_stackUpdated = false;
        m_attackStateManager.pushState(std::make_shared<SearchState>(m_attackStateManager, m_playingAgainst,
                                                                     m_remainingTargets, result));
    }
}

void SearchState::newDirections()
{
    std::deque<Direction> possibleDirections = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(possibleDirections.begin(), possibleDirections.end(), g);

    while(!possibleDirections.empty())
    {
        m_directions.emplace(possibleDirections.front());
        std::cout << "Search state | Possible direction " << m_directions.top().row << ", " << m_directions.top().col << " added to stack\n";
        possibleDirections.pop_front();
    }
}

std::string SearchState::getType()
{
    return "search state";
}
