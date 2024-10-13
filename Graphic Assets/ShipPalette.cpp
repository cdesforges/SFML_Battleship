//
// Created by Chandler Desforges on 6/8/24.
//

#include "ShipPalette.h"

ShipPalette::ShipPalette(sf::Vector2f position) :
m_position(position),
m_title("Ships to place:", position, 30)
{
    initialize();
}

void ShipPalette::initialize()
{
    m_ships.emplace_back(std::make_shared<Ship>(DESTROYER, sf::Vector2f(m_position.x - 100.f, m_position.y + 150.f), VERTICAL));
    m_ships.emplace_back(std::make_shared<Ship>(SUBMARINE, sf::Vector2f(m_position.x - 50.f, m_position.y + 150.f), VERTICAL));
    m_ships.emplace_back(std::make_shared<Ship>(JEFF, sf::Vector2f(m_position.x, m_position.y + 150.f), VERTICAL));
    m_ships.emplace_back(std::make_shared<Ship>(BATTLESHIP, sf::Vector2f(m_position.x + 50.f, m_position.y + 150.f), VERTICAL));
    m_ships.emplace_back(std::make_shared<Ship>(CARRIER, sf::Vector2f(m_position.x + 100.f, m_position.y + 150.f), VERTICAL));
}

void ShipPalette::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for(auto& ship : m_ships)
    {
        window.draw(*ship);
    }

    window.draw(m_title);
}

std::vector<std::shared_ptr<Ship>> ShipPalette::getShips()
{
    return m_ships;
}

bool ShipPalette::isShipHovered(sf::RenderWindow& window)
{
    for (auto &ship : m_ships)
    {
        if (ship->isHovered(window))
        {
            return true;
        }
    }

    return false;
}

void ShipPalette::selectShip(sf::RenderWindow &window)
{
    // if new drag
    if(m_selectedShip == nullptr)
    {
        // check which ship is hovered and set pointer to that ship
        for (auto& ship : m_ships)
            if (ship->isHovered(window))
                m_selectedShip = ship;

        // set new drag offset
        setDragOffset(window);
    }
}

void ShipPalette::setDragOffset(sf::RenderWindow& window)
{
    if(m_selectedShip != nullptr)
    m_dragOffset = m_selectedShip->getPosition() - static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
}

void ShipPalette::dragShip(sf::RenderWindow &window)
{
    if(m_selectedShip != nullptr)
        m_selectedShip->setPosition(sf::Mouse::getPosition(window) + static_cast<sf::Vector2i>(m_dragOffset));
}

void ShipPalette::releaseShip()
{
    if(m_selectedShip != nullptr)
        m_selectedShip = nullptr;
}

void ShipPalette::rotateShip()
{
    if(m_selectedShip != nullptr)
        m_selectedShip->rotate();
}

void ShipPalette::setSelectedShipPosition(const sf::Vector2f &position)
{
    if(m_selectedShip != nullptr)
        m_selectedShip->setPosition(static_cast<sf::Vector2i>(position));
}
