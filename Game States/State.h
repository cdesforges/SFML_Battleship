//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_STATE_H
#define INC_06_LAB_BATTLESHIP_STATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <stack>
#include <memory>
#include "../ComPlayer.h"

class StateManager;

class State
{
protected:
    sf::RenderWindow& m_window;
    StateManager& m_stateManager;

public:
    State(sf::RenderWindow &window, StateManager &stateManager);
    virtual ~State() = default;

    virtual void eventHandler() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};

using StatePtr = std::shared_ptr<State>;
using MusicPtr = std::shared_ptr<sf::Music>;
using PlayerPtr = std::shared_ptr<Player>;


#endif //INC_06_LAB_BATTLESHIP_STATE_H
