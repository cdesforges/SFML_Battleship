//
// Created by Chandler Desforges on 6/8/24.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow &window, StateManager &stateManager) :
State(window, stateManager),
m_startButton(50,{790,450},"start"),
m_title("Battleship",{800,300},120),
m_background(),
m_mainMenuMusic(std::make_shared<sf::Music>())
{
    initialize();
}

void MainMenuState::initialize()
{
    if(!m_backgroundTexture.loadFromFile("battleship_mm_background.png"))
        std::cout << "Error loading main menu background texture!\n";

    m_background.setTexture(m_backgroundTexture);

    if(!m_mainMenuMusic->openFromFile("main_menu_mx.ogg"))
        std::cout << "Failed to load music in main menu!\n";

    m_mainMenuMusic->setLoop(true);
    m_mainMenuMusic->play();
}

void MainMenuState::update()
{
    // update button state
    m_startButton.update(m_window);
}

void MainMenuState::draw()
{
    // draw everything
    m_window.draw(m_background);
    m_window.draw(m_title);
    m_window.draw(m_startButton);
}

void MainMenuState::eventHandler()
{
    sf::Event event;

    while(event.type == m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
            case sf::Event::MouseButtonPressed:
                mouseButtonPressed();
        }
    }
}

void MainMenuState::mouseButtonPressed()
{
    if(m_startButton.contains(sf::Mouse::getPosition(m_window)))
    {
        m_stateManager.replaceState(std::make_shared<PlaceShipsState>(m_window, m_stateManager, m_mainMenuMusic));
    }
}
