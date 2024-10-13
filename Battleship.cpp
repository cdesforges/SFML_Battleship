//
// Created by Chandler Desforges on 5/16/24.
//

#include "Battleship.h"

void Battleship::run()
{
    Rand::seed();

    sf::RenderWindow window({1600,800}, "Battleship", sf::Style::Default);
    window.setFramerateLimit(60);

    StateManager stateManager;
    stateManager.pushState(std::make_shared<MainMenuState>(window, stateManager));

    while(window.isOpen())
    {
        stateManager.getCurrentState()->eventHandler();
        stateManager.getCurrentState()->update();
        window.clear();
        stateManager.getCurrentState()->draw();
        window.display();
    }
}
