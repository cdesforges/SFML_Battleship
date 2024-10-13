//
// Created by Chandler Desforges on 6/13/24.
//

#include "AttackState.h"

AttackState::AttackState(AttackStateManager& attackStateManager, Player& playingAgainst, std::deque<Coordinates>& remainingMoves) :
        m_attackStateManager(attackStateManager),
        m_playingAgainst(playingAgainst),
        m_remainingTargets(remainingMoves),
        m_stackUpdated(false)
{}

bool AttackState::isLegalMove(Coordinates move)
{
    if(move.col < 0 || move.col > 9)
        return false;
    if(move.row < 0 || move.row > 9)
        return false;

    for(auto &nextMoves : m_remainingTargets)
    {
        if(move == nextMoves)
            return true;
    }

    return false;
}

int AttackState::toInt(Coordinates move)
{
    return move.row * 10 + move.col;
}

Row AttackState::toRow(int rowIndex)
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

bool AttackState::findAndMoveToFront(const Coordinates &value)
{
//    std::cout << "Initial deq: \n";
//    printDeq();

    // Find the element in the deque
    auto it = std::find(m_remainingTargets.begin(), m_remainingTargets.end(), value);

    // If the element is found, attack it to the front
    if (it != m_remainingTargets.end()) {
        std::cout << "Found element: " << (char)(it->row + 'A') << ", " << it->col << " at position " << std::distance(m_remainingTargets.begin(), it) << std::endl;

        // Remove the element from its current position
        Coordinates foundElement = *it;
        std::cout << "Erased element at: " << std::distance(m_remainingTargets.begin(), it) << std::endl;
        m_remainingTargets.erase(it);

        // Insert the element at the front
        m_remainingTargets.push_front(foundElement);
        std::cout << "Moved element to the front: " << (char)(foundElement.row + 'A') << ", " << foundElement.col << std::endl;
        std::cout << std::endl;

//        printDeq();
        return true;
    } else {
        std::cout << "Element not found" << std::endl;
    }

//    printDeq();
    return false;
}

std::string AttackState::toString(const ShipType &shipType)
{
    switch(shipType)
    {
        case DESTROYER:
            return "destroyer";
        case SUBMARINE:
            return "submarine";
        case JEFF:
            return "jeff";
        case BATTLESHIP:
            return "battleship";
        case CARRIER:
            return "carrier";
        case EMPTY:
            return "miss";
        default:
            return "default tostring ship";
    }
}
