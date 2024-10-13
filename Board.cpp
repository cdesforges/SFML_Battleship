//
// Created by Chandler Desforges on 5/16/24.
//

#include "Board.h"

sf::Font Board::m_retro = loadFont();

Board::Board(sf::Vector2f startPosition) :
m_boardSize(10),
m_position(startPosition),
m_startColor(sf::Color::White)
{
    initializeBoard();
}

void Board::initializeBoard()
{
    initializeAxisLabels();
    initializeSquares();
}

void Board::reset()
{
    for(auto& square : m_allSquares)
        square.setFillColor(sf::Color::White);
}

void Board::update(float& dt)
{
    for(auto &square : m_allSquares)
        square.update(dt);
}

void Board::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_colLabel);
    window.draw(m_rowLabel);

    for(const auto& square : m_allSquares)
        window.draw(square);
}

sf::Font Board::loadFont()
{
    sf::Font font;

    if(!font.loadFromFile("font.ttf"))
        std::cout << "Couldn't load font!";

    return font;
}

int Board::toInt(Coordinates move)
{
    return move.row * 10 + move.col;
}

void Board::setHoveredSquares(const std::shared_ptr<Ship>& ship)
{
    for (auto &square : m_allSquares)
    {
        if (square.getShape().getGlobalBounds().intersects(ship->getShipShape().getGlobalBounds()))
        {
            square.setFillColor(sf::Color::Red);
        }
    }
}

void Board::addShipPtrs(const std::shared_ptr<Ship>& ship)
{
    for (auto &square: m_allSquares)
        if (square.getShape().getGlobalBounds().intersects(ship->getShipShape().getGlobalBounds()))
            square.setShipPtr(ship);
}

void Board::initializeAxisLabels()
{
    m_colLabel.setString("    0   1   2   3   4  5   6   7   8  9");
    m_colLabel.setPosition(m_position);
    m_colLabel.setFillColor(sf::Color::White);
    m_colLabel.setFont(m_retro);

    m_rowLabel.setString("\n\nA\n\nB\n\nC\n\nD\n\nE\n\nF\n\nG\n\nH\n\nI\n\nJ");
    m_rowLabel.setPosition(m_position);
    m_rowLabel.setFillColor(sf::Color::White);
    m_rowLabel.setFont(m_retro);
}

void Board::initializeSquares()
{
    for(int row = 0; row < m_boardSize; row++)
        for(int col = 0; col < m_boardSize; col++)
            m_allSquares.emplace_back(m_squareSize,
                                      sf::Vector2f(m_position.x + (m_squareSize * (float)col) + (m_bufferSize * (float)col + m_bufferSize * 4.3f),
                                                             m_position.y + (m_squareSize * (float)row) + (m_bufferSize * (float)row) + m_bufferSize * 5.5f),
                                      m_startColor,
                                      Coordinates(row, col));
}

void Board::printInfo()
{
    for(auto &square : m_allSquares)
    {
        if(square.getShipPtr() != nullptr)
        {
            std::cout << "Ship pointer: " << square.getShipPtr() << "\n";
            std::cout << "Coordinates of ";
            std::cout << toString(square.getShipPtr()->getShipType());
            std::cout << " is " << square.getCoordinates().row << ", " << square.getCoordinates().col;
            std::cout << " and it's health is " << square.getShipPtr()->getHealth() << "\n";
        }
    }
}

void Board::placeRandom(const std::shared_ptr<Ship>& ship)
{
    std::vector<Coordinates> possibleCoordinates;
    Coordinates randomStart;
    bool legalMove;

    do
    {
        legalMove = true;
        possibleCoordinates.clear();

        if(ship->getOrientation() == HORIZONTAL)
        {
            randomStart = {Rand::rint(0,9), Rand::rint(0,9 - ship->getLength())};
            for(int i = 0; i < ship->getLength(); i++)
            {
                possibleCoordinates.emplace_back(randomStart.row, randomStart.col + i);
            }
        }
        else
        {
            randomStart = {Rand::rint(0,9 - ship->getLength()), Rand::rint(0,9)};
            for(int i = 0; i < ship->getLength(); i++)
            {
                possibleCoordinates.emplace_back(randomStart.row + i, randomStart.col);
            }
        }

        for(auto& coords : possibleCoordinates)
        {
            for(auto& square : m_allSquares)
            {
                if(square.getCoordinates() == coords)
                {
                    if (square.getShipPtr() != nullptr)
                    {
                        legalMove = false;
                        break;
                    }
                }
            }
        }
    } while(!legalMove);

    for(auto& coords : possibleCoordinates)
        for(auto& square : m_allSquares)
            if(square.getCoordinates() == coords)
                square.setShipPtr(ship);
}

std::string Board::toString(const ShipType &shipType)
{
    switch(shipType)
    {
        case DESTROYER:
            return "destroyer";
        case SUBMARINE:
            return "submarine";
        case JEFF:
            return "jeff";
        case BATTLESHIP:
            return "battleship";
        case CARRIER:
            return "carrier";
        case EMPTY:
            return "miss";
        default:
            return "default";
    }
}

// returns a result as a hit result struct
HitResult Board::attack(const Coordinates &coordinates)
{
    // attack square and capture result
    HitResult result = m_allSquares[toInt(coordinates)].attack();

    std::cout << "Attack function post-result | result.shipType = " << toString(result.shipType) << ", result.shipHealth = " << result.shipHealth << std::endl;

    return result;
}

bool Board::clicked(const sf::RenderWindow &window)
{
    for(auto &square : m_allSquares)
        if(square.isHovered(window))
            square.attack();

    return true;
}

sf::Vector2f Board::getPositionOfHoveredSquare(const sf::Vector2f& position)
{
    for(auto& square : m_allSquares)
        if(square.containsPosition(position))
            return square.getShape().getPosition();

    return position;
}
