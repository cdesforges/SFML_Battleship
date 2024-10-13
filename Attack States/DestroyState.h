//
// Created by Chandler Desforges on 6/15/24.
//

#ifndef INC_06_LAB_BATTLESHIP_DESTROYSTATE_H
#define INC_06_LAB_BATTLESHIP_DESTROYSTATE_H


#include "AttackState.h"
#include "../Direction.h"
#include "SearchState.h"
#include "RandomAttackState.h"

class DestroyState : public AttackState
{
private:
    Direction m_direction;
    HitResult m_secondHit;

public:
    DestroyState(AttackStateManager& attackStateManager, Player& playingAgainst, std::deque<Coordinates>& remainingTargets, const HitResult& anchorHit, const HitResult& secondHit);
    ~DestroyState() = default;

    // inherited
    void updateStack() override;
    void attack() override;
    std::string getType() override;
};


#endif //INC_06_LAB_BATTLESHIP_DESTROYSTATE_H
