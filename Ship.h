//
// Created by Chandler Desforges on 5/16/24.
//

#ifndef INC_06_LAB_BATTLESHIP_SHIP_H
#define INC_06_LAB_BATTLESHIP_SHIP_H

#include <iostream>
#include "Coordinates.h"
#include "Enums.h"
#include <vector>
#include <utility>
#include <random>
#include "Rand.h"
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

class Ship : public sf::Drawable
{
private:
    // logic attributes
    int m_length;
    ShipType m_shipType;
    int m_shipHealth;
    bool m_isVisible;

    // graphic attributes
    sf::Sprite m_shipShape;
    sf::Texture* m_shipTexture;
    sf::Vector2f m_position;
    Orientation m_orientation;

    // static counter
    static int m_numShips;

public:

    //constructors
    Ship(ShipType shipType, sf::Vector2f position, Orientation orientation);
    ~Ship();
    void setInitialState(const ShipType &shipType);

    // inherited
    void draw(sf::RenderTarget &window, sf::RenderStates state) const override;

    // getters
    ShipType getShipType();
    int getHealth() const;
    sf::Color getShipColor();
    int getLength() const;
    Orientation getOrientation();
    bool getIsVisible();
    static int getNumShips();

    // graphic
    bool isHovered(const sf::RenderWindow& window);
    sf::Vector2f getPosition();
    sf::Sprite getShipShape();

    // setters
    void setTexture(ShipType shipType);
    void setPosition(sf::Vector2<int> position);
    void setIsVisible(bool value);

    // actions
    void missileHit();
    void rotate();

};


#endif //INC_06_LAB_BATTLESHIP_SHIP_H
