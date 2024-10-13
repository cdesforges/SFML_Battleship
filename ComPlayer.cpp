//
// Created by Chandler Desforges on 6/6/24.
//

#include "ComPlayer.h"

ComPlayer::ComPlayer(Player& playingAgainst) :
m_comAI(playingAgainst)
{
    m_allShips.emplace_back(std::make_shared<Ship>(DESTROYER, sf::Vector2f(0.f,0.f), RANDOM));
    m_allShips.emplace_back(std::make_shared<Ship>(SUBMARINE, sf::Vector2f(0.f,0.f), RANDOM));
    m_allShips.emplace_back(std::make_shared<Ship>(JEFF, sf::Vector2f(0.f,0.f), RANDOM));
    m_allShips.emplace_back(std::make_shared<Ship>(BATTLESHIP, sf::Vector2f(0.f,0.f), RANDOM));
    m_allShips.emplace_back(std::make_shared<Ship>(CARRIER, sf::Vector2f(0.f,0.f), RANDOM));

    m_board = Board({100,100});

    placeShipsOnBoard();

    initialize();
}

void ComPlayer::move()
{
    m_comAI.attack();
}