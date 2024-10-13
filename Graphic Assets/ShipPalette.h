//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_SHIPPALETTE_H
#define INC_06_LAB_BATTLESHIP_SHIPPALETTE_H

#include <vector>
#include "../Ship.h"
#include "Menu.h"

class ShipPalette : public sf::Drawable
{
private:
    std::vector<std::shared_ptr<Ship>> m_ships;
    Menu m_title;
    sf::Vector2f m_position;
    sf::Vector2f m_dragOffset;
    std::shared_ptr<Ship> m_selectedShip;


public:
    ShipPalette() = default;
    explicit ShipPalette(sf::Vector2f position);
    ~ShipPalette() override = default;
    void initialize();

    // inherited
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;

    // getters
    std::vector<std::shared_ptr<Ship>> getShips();
    bool isShipHovered(sf::RenderWindow& window);

    // setters
    void setSelectedShipPosition(const sf::Vector2f& position);

    // functions
    void selectShip(sf::RenderWindow& window);
    void dragShip(sf::RenderWindow& window);
    void setDragOffset(sf::RenderWindow& window);
    void releaseShip();
    void rotateShip();
};


#endif //INC_06_LAB_BATTLESHIP_SHIPPALETTE_H
