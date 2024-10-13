//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_PLACESHIPSSTATE_H
#define INC_06_LAB_BATTLESHIP_PLACESHIPSSTATE_H

#include "../ComPlayer.h"
#include "State.h"
#include "StateManager.h"
#include "MainMenuState.h"
#include "MainGameState.h"
#include "../Graphic Assets/Menu.h"
#include "../Graphic Assets/ShipPalette.h"
#include "../Graphic Assets/Button.h"
#include <memory>

class PlaceShipsState : public State
{
private:
    Player m_p1;
    Menu m_title;
    ShipPalette m_shipPalette;
    MusicPtr m_music;
    Button m_startButton;

    float m_dt;
    sf::Clock m_clock;
    sf::Cursor m_cursor;

public:
    PlaceShipsState(sf::RenderWindow &window, StateManager &stateManager, MusicPtr music);
    ~PlaceShipsState() override = default;

    // functions
    void selectShip(sf::Event& event);
    void dragShip(sf::Event& event);
    void releaseShip(sf::Event& event);
    void rotateShip(sf::Event& event);
    void updateCursor();
    void updateHoveredSquares();
    void checkForStart();
    void addShipsToPlayer();
    void snapShips();

    // inherited
    void eventHandler() override;
    void update() override;
    void draw() override;
};


#endif //INC_06_LAB_BATTLESHIP_PLACESHIPSSTATE_H
