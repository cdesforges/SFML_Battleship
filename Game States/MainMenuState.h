//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_MAINMENUSTATE_H
#define INC_06_LAB_BATTLESHIP_MAINMENUSTATE_H


#include "State.h"
#include "StateManager.h"
#include "MainGameState.h"
#include "PlaceShipsState.h"
#include "../Graphic Assets/Menu.h"
#include "../Graphic Assets/Button.h"

class MainMenuState : public State
{
private:
    // visual
    Menu m_title;
    sf::Sprite m_background;
    sf::Texture m_backgroundTexture;
    Button m_startButton;

    // audio
    MusicPtr m_mainMenuMusic;

public:
    MainMenuState(sf::RenderWindow& window, StateManager& stateManager);
    ~MainMenuState() override = default;
    void initialize();

    // functions
    void mouseButtonPressed();

    // inherited
    void eventHandler() override;
    void update() override;
    void draw() override;
};


#endif //INC_06_LAB_BATTLESHIP_MAINMENUSTATE_H
