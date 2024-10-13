//
// Created by Chandler Desforges on 6/13/24.
//

#ifndef INC_06_LAB_BATTLESHIP_SEARCHSTATE_H
#define INC_06_LAB_BATTLESHIP_SEARCHSTATE_H


#include "AttackState.h"
#include "../Player.h"
#include "DestroyState.h"

class SearchState : public AttackState
{
private:
    std::stack<Direction> m_directions;

public:
    SearchState(AttackStateManager& attackStateManager, Player& playingAgainst, std::deque<Coordinates>& remainingTargets, const HitResult& anchorHit);

    // inherited
    void updateStack() override;
    void attack() override;
    std::string getType() override;

    void newDirections();

};


#endif //INC_06_LAB_BATTLESHIP_SEARCHSTATE_H
