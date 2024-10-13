//
// Created by Chandler Desforges on 5/16/24.
//

#ifndef INC_06_LAB_BATTLESHIP_BOARD_H
#define INC_06_LAB_BATTLESHIP_BOARD_H

#include "Ship.h"
#include "Graphic Assets/Square.h"
#include "Coordinates.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enums.h"
#include "HitResult.h"

class Board : public sf::Drawable
{
private:
    // main attributes
    sf::Vector2f m_position;
    int m_boardSize;

    // assets
    std::vector<Square> m_allSquares;

    // attributes
    float m_squareSize = 50;
    float m_bufferSize = 10;
    sf::Color m_startColor = sf::Color::Blue;
    sf::Text m_colLabel;
    sf::Text m_rowLabel;
    static sf::Font m_retro;

public:
    explicit Board(sf::Vector2f startPosition);
    void initializeBoard();
    void initializeAxisLabels();
    void initializeSquares();

    // inherited
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

    // setters
    void setHoveredSquares(const std::shared_ptr<Ship>& ship);
    void addShipPtrs(const std::shared_ptr<Ship>& ship);

    // functions
    void reset();
    static sf::Font loadFont();
    static int toInt(Coordinates move);
    void printInfo();
    void update(float& dt);
    bool clicked(const sf::RenderWindow &window);
    void placeRandom(const std::shared_ptr<Ship>& ship);
    HitResult attack(const Coordinates& coordinates);
    sf::Vector2f getPositionOfHoveredSquare(const sf::Vector2f& position);
    static std::string toString(const ShipType& shipType);
};


#endif //INC_06_LAB_BATTLESHIP_BOARD_H
