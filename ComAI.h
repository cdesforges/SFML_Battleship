//
// Created by Chandler Desforges on 6/9/24.
//

#ifndef INC_06_LAB_BATTLESHIP_COMAI_H
#define INC_06_LAB_BATTLESHIP_COMAI_H

#include "Coordinates.h"
#include <deque>
#include <vector>
#include <stack>
#include "Board.h"
#include "Player.h"
#include "Attack States/AttackState.h"
#include "Attack States/AttackStateManager.h"
#include "Attack States/SearchState.h"
#include "Attack States/RandomAttackState.h"

class ComAI
{
private:
    std::deque<Coordinates> m_remainingTargets;
    std::stack<std::pair<int, int>> m_directions; // attack to searching state
    AttackStateManager m_attackStateManager;

    Player& m_playingAgainst;

private:
    void initializeMoveStack();
    Row toRow(int rowIndex);


public:
    ComAI(Player& playingAgainst);
    ~ComAI() = default;

    void attack();
};


#endif //INC_06_LAB_BATTLESHIP_COMAI_H
