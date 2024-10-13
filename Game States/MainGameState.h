//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_MAINGAMESTATE_H
#define INC_06_LAB_BATTLESHIP_MAINGAMESTATE_H


#include "State.h"
#include "StateManager.h"
#include "EndGameState.h"
#include "../ComPlayer.h"
#include "../ComPlayer.h"
#include "../Graphic Assets/Menu.h"
#include "../ComAI.h"

class MainGameState : public State
{
private:
    Player m_p1;
    ComPlayer m_com;
    bool m_playerWent;
    float m_timeElapsed;
    Menu m_title;
    float m_dt;
    sf::Clock m_clock;

public:
    MainGameState(sf::RenderWindow &window, StateManager &stateManager, Player& initialPlayer);
    ~MainGameState() override = default;

    // inherited
    void eventHandler() override;
    void update() override;
    void draw() override;

    // functions
    void comMove();
    void checkForEndGame();



};


#endif //INC_06_LAB_BATTLESHIP_MAINGAMESTATE_H
