//
// Created by Chandler Desforges on 7/9/24.
//

#ifndef INC_06_LAB_BATTLESHIP_ENDGAMESTATE_H
#define INC_06_LAB_BATTLESHIP_ENDGAMESTATE_H

#include "State.h"
#include "StateManager.h"
#include "MainMenuState.h"
#include "../Graphic Assets/Menu.h"
#include "../Graphic Assets/Button.h"

class EndGameState : public State
{
private:
    Menu m_result;
    Button m_playAgainButton;

public:
    EndGameState(sf::RenderWindow &window, StateManager &stateManager, const bool &playerWon);
    ~EndGameState() = default;
    void initialize(const bool &playerWon);

    // functions
    void mouseButtonPressed();

    // inherited
    void eventHandler() override;
    void update() override;
    void draw() override;
};


#endif //INC_06_LAB_BATTLESHIP_ENDGAMESTATE_H
