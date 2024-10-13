//
// Created by Chandler Desforges on 6/13/24.
//

#ifndef INC_06_LAB_BATTLESHIP_ATTACKSTATE_H
#define INC_06_LAB_BATTLESHIP_ATTACKSTATE_H

#include <stack>
#include "../Coordinates.h"
#include "../Player.h"
#include "AttackStateManager.h"
#include "../HitResult.h"

class AttackStateManager;

class AttackState
{
protected:
    AttackStateManager& m_attackStateManager;
    std::deque<Coordinates>& m_remainingTargets;
    Player& m_playingAgainst;
    HitResult m_anchorHit;
    bool m_stackUpdated;

    bool isLegalMove(Coordinates move);
    static int toInt(Coordinates move);
    Row toRow(int rowIndex);
    bool findAndMoveToFront(const Coordinates& value);
    static std::string toString(const ShipType& shipType);

public:
    AttackState(AttackStateManager& attackStateManager, Player& playingAgainst, std::deque<Coordinates>& remainingMoves);
    virtual ~AttackState() = default;

    virtual void updateStack() = 0;
    virtual void attack() = 0;
    virtual std::string getType() = 0;

};

using AttackStatePtr = std::shared_ptr<AttackState>;


#endif //INC_06_LAB_BATTLESHIP_ATTACKSTATE_H
