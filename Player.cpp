//
// Created by Chandler Desforges on 6/9/24.
//

#include "Player.h"

Player::Player() :
m_board({900,100})
{
    initialize();
}

void Player::initialize()
{
    for(auto& ship : m_allShips)
        ship->setIsVisible(false);

    m_board.reset();
}

Board Player::getBoard()
{
    return m_board;
}

void Player::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_board);
    for(auto& ship : m_allShips)
        window.draw(*ship);

}

bool Player::clicked(sf::RenderWindow &window)
{
    return m_board.clicked(window);
}

void Player::placeShipsOnBoard()
{
    for(auto &ship : m_allShips)
    {
        m_board.placeRandom(ship);
    }
}

void Player::update(float& dt)
{
    m_board.update(dt);
}

void Player::resetSquares()
{
    m_board.reset();
}

void Player::addShips(const std::vector<std::shared_ptr<Ship>> &ships)
{
    m_allShips = ships;
    updateShipPtrs();
}

void Player::setHoveredSquares(const std::shared_ptr<Ship>& ship)
{
    m_board.setHoveredSquares(ship);
}

HitResult Player::attack(const Coordinates& coordinates)
{
    return m_board.attack(coordinates);
}

void Player::updateShipPtrs()
{
    for(auto& ship : m_allShips)
        m_board.addShipPtrs(ship);
}

sf::Vector2f Player::getPositionOfHoveredSquare(const sf::Vector2f &position)
{
    return m_board.getPositionOfHoveredSquare(position);
}

int Player::getNumAliveShips()
{
    int numAlive = 0;

    for(auto& ship : m_allShips)
        if(ship->getHealth() > 0)
            numAlive++;

    return numAlive;
}
