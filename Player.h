//
// Created by Chandler Desforges on 6/9/24.
//

#ifndef INC_06_LAB_BATTLESHIP_PLAYER_H
#define INC_06_LAB_BATTLESHIP_PLAYER_H

#include "Board.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "HitResult.h"

class Player : public sf::Drawable
{
protected:
    Board m_board;
    std::vector<std::shared_ptr<Ship>> m_allShips;

public:
    Player();
    ~Player() override = default;
    void initialize();

    // to children
    bool clicked(sf::RenderWindow& window);
    void placeShipsOnBoard();

    // getters
    Board getBoard();
    int getNumAliveShips();

    // setters
    void setHoveredSquares(const std::shared_ptr<Ship>& ship);

    // inherited
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

    // functions
    void update(float& dt);
    void resetSquares();
    void addShips(const std::vector<std::shared_ptr<Ship>>& ships);
    HitResult attack(const Coordinates& coordinates);
    void updateShipPtrs();
    sf::Vector2f getPositionOfHoveredSquare(const sf::Vector2f& position);


};


#endif //INC_06_LAB_BATTLESHIP_PLAYER_H
