//
// Created by Chandler Desforges on 6/8/24.
//

#include "MainGameState.h"

#include <utility>

// com board (left) that user is guessing on
// user board (right) that com is guessing on

MainGameState::MainGameState(sf::RenderWindow &window, StateManager &stateManager, Player& initialPlayer) :
State{window, stateManager},
m_title("Battleship",{800,30},50),
m_playerWent(false),
m_dt(0.f),
m_timeElapsed(0),
m_p1(initialPlayer),
m_com(m_p1)
{
    m_p1.getBoard().printInfo();
}

void MainGameState::update()
{
    // com moves
    comMove();

    //update
    m_p1.update(m_dt);
    m_com.update(m_dt);

    //check for end game
    checkForEndGame();
}

void MainGameState::draw()
{
    //draw everything
    m_window.draw(m_p1);
    m_window.draw(m_com);
    m_window.draw(m_title);
}

void MainGameState::eventHandler()
{
    m_dt = m_clock.restart().asSeconds();

    sf::Event event;

    while(m_window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonPressed:
                m_playerWent = m_com.clicked(m_window);

        }
    }
}

void MainGameState::comMove()
{
    if(m_playerWent)
    {
        m_timeElapsed += m_dt;
        if(m_timeElapsed > 0.5)
        {
            m_com.move();
            m_playerWent = false;
            m_timeElapsed = 0;
        }
    }
}

void MainGameState::checkForEndGame()
{
    if(m_p1.getNumAliveShips() == 0)
        m_stateManager.replaceState(std::make_shared<EndGameState>(m_window, m_stateManager, false));
    else if(m_com.getNumAliveShips() == 0)
        m_stateManager.replaceState(std::make_shared<EndGameState>(m_window, m_stateManager, true));
}
