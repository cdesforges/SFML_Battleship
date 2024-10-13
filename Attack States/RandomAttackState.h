//
// Created by Chandler Desforges on 6/15/24.
//

#ifndef INC_06_LAB_BATTLESHIP_RANDOMATTACKSTATE_H
#define INC_06_LAB_BATTLESHIP_RANDOMATTACKSTATE_H


#include "AttackState.h"
#include "SearchState.h"

class RandomAttackState : public AttackState
{

public:
    RandomAttackState(AttackStateManager& attackStateManager, Player& playingAgainst, std::deque<Coordinates>& remainingTargets);
    ~RandomAttackState() = default;

    // inherited
    void updateStack() override;
    void attack() override;
    std::string getType() override;

};


#endif //INC_06_LAB_BATTLESHIP_RANDOMATTACKSTATE_H
