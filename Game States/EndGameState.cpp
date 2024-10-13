//
// Created by Chandler Desforges on 7/9/24.
//

#include "EndGameState.h"

EndGameState::EndGameState(sf::RenderWindow &window, StateManager &stateManager, const bool &playerWon) : State(window, stateManager),
m_playAgainButton(50, {790, 450}, "play again?"),
m_result("default",{750,300},80)
{
    initialize(playerWon);
}

void EndGameState::initialize(const bool &playerWon)
{
    if(playerWon)
        m_result.setText("you won!");
    else
        m_result.setText("you lost :/");
}

void EndGameState::mouseButtonPressed()
{
    if(m_playAgainButton.contains(sf::Mouse::getPosition(m_window)))
        m_stateManager.replaceState(std::make_shared<MainMenuState>(m_window, m_stateManager));
}

void EndGameState::eventHandler()
{
    std::cout << "Checkpoint 1\n";

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

    std::cout << "Checkpoint 2\n";

}

void EndGameState::update()
{
    std::cout << "Checkpoint 3\n";
    m_playAgainButton.update(m_window);
    std::cout << "Checkpoint 4\n";
}

void EndGameState::draw()
{
    std::cout << "Checkpoint 5\n";
    m_window.draw(m_result);
    std::cout << "Checkpoint 6\n";
    m_window.draw(m_playAgainButton);
    std::cout << "Checkpoint 7\n";
}
