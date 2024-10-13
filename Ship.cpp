//
// Created by Chandler Desforges on 5/16/24.
//

#include "Ship.h"

#include <utility>

int Ship::m_numShips = 0;

Ship::Ship(ShipType shipType, sf::Vector2f position, Orientation orientation) :
m_length(),
m_shipHealth(),
m_orientation(orientation),
m_shipType(shipType),
m_shipShape(),
m_isVisible(true),
m_shipTexture(&TextureManager::getTexture(shipType))
{
    setInitialState(shipType);
    m_shipShape.setOrigin((m_shipShape.getLocalBounds().left + m_shipShape.getLocalBounds().width) / 2.f,
                          (m_shipShape.getLocalBounds().top + m_shipShape.getLocalBounds().height) / 2.f); // STOPPED HERE set origin of ship so it snaps to square!
    m_shipShape.setPosition(position);
    m_numShips++;
}

Ship::~Ship()
{
    m_numShips--;
}

ShipType Ship::getShipType()
{
    return m_shipType;
}

Orientation Ship::getOrientation()
{
    return m_orientation;
}

void Ship::missileHit()
{
    m_shipHealth--;
//    if(m_shipHealth == 0)
//        m_isVisible = true;
// TODO make ships appear when sunk
}

void Ship::setInitialState(const ShipType &shipType)
{
    if(m_orientation == RANDOM)
    {
        if(Rand::rint(0,1))
            m_orientation = VERTICAL;
        else
            m_orientation = HORIZONTAL;
    }

    m_shipType = shipType;

    switch(shipType)
    {
        case DESTROYER:
            m_length = 2;
            m_shipHealth = 2;
            setTexture(DESTROYER);
            m_shipShape.setOrigin({25.f, 25.f});
            break;
        case SUBMARINE:
            m_length = 3;
            m_shipHealth = 3;
            setTexture(SUBMARINE);
            m_shipShape.setOrigin({25.f, 25.f});
            break;
        case JEFF:
            m_length = 3;
            m_shipHealth = 3;
            setTexture(JEFF);
            m_shipShape.setOrigin({25.f, 25.f});
            break;
        case BATTLESHIP:
            m_length = 4;
            m_shipHealth = 4;
            setTexture(BATTLESHIP);
            m_shipShape.setOrigin({25.f, 25.f});
            break;
        case CARRIER:
            m_length = 5;
            m_shipHealth = 5;
            setTexture(CARRIER);
            m_shipShape.setOrigin({25.f, 25.f});
    }
}

int Ship::getHealth() const
{
    return m_shipHealth;
}

sf::Color Ship::getShipColor()
{
    switch(m_shipType)
    {
        case DESTROYER:
            return {0,0,255,50};
        case SUBMARINE:
            return {0,0,255,100};
        case JEFF:
            return {0,0,255,150};
        case BATTLESHIP:
            return {0,0,255,200};
        case CARRIER:
            return {0,0,255,255};
    }
}

int Ship::getLength() const
{
    return m_length;
}

void Ship::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    if(m_isVisible)
        window.draw(m_shipShape);
}

void Ship::setTexture(ShipType shipType)
{
    m_shipShape.setTexture(*m_shipTexture);
}

bool Ship::isHovered(const sf::RenderWindow &window)
{
    if((float)sf::Mouse::getPosition(window).x > m_shipShape.getGlobalBounds().left
       && (float)sf::Mouse::getPosition(window).x < m_shipShape.getGlobalBounds().left + m_shipShape.getGlobalBounds().width)
    {
        if((float)sf::Mouse::getPosition(window).y > m_shipShape.getGlobalBounds().top
           && (float)sf::Mouse::getPosition(window).y < m_shipShape.getGlobalBounds().top + m_shipShape.getGlobalBounds().height)
        {
            return true;
        }
    }

    return false;
}

void Ship::setPosition(sf::Vector2<int> position)
{
    m_shipShape.setPosition((sf::Vector2f)(position));
}

sf::Vector2f Ship::getPosition()
{
    return m_shipShape.getPosition();
}

sf::Sprite Ship::getShipShape()
{
    return m_shipShape;
}

void Ship::rotate()
{
    m_shipShape.rotate(90.f);

    if(m_orientation == VERTICAL)
        m_orientation = HORIZONTAL;
    else
        m_orientation = VERTICAL;
}

bool Ship::getIsVisible()
{
    return m_isVisible;
}

void Ship::setIsVisible(bool value)
{
    m_isVisible = value;
}

int Ship::getNumShips()
{
    return m_numShips;
}
