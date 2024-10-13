//
// Created by Chandler Desforges on 5/31/24.
//

#ifndef INC_06_LAB_BATTLESHIP_SQUARE_H
#define INC_06_LAB_BATTLESHIP_SQUARE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Ship.h"
#include "../Coordinates.h"
#include "Animation.h"
#include "HitAnimation.h"
#include "../HitResult.h"

class Square : public sf::Drawable
{
private:
    // graphic attributes
    sf::Sprite m_shape;
    static sf::Texture m_texture;
    Animation m_animation;
    sf::Text m_debugText;
    static sf::Font m_font;
    sf::Color m_color;
    std::vector<HitAnimation> m_explosions;

    // logic attributes
    Coordinates m_coordinates;
    std::shared_ptr<Ship> m_shipPointer;

public:
    Square(const float &size, const sf::Vector2f &position, const sf::Color &color, Coordinates coordinates);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    // getters
    sf::Sprite& getShape();
    std::shared_ptr<Ship> getShipPtr();
    Coordinates getCoordinates();
    sf::Color getFillColor();
    bool containsPosition(const sf::Vector2f& position);

    // setters
    void setFillColor(const sf::Color &color);
    void setShipPtr(const std::shared_ptr<Ship>& ship);

    //functions
    HitResult attack();
    bool isHovered(const sf::RenderWindow &window);
    void update(float dt);
    void setDebugText(int index);
    void setDebugText(std::string string);
    void hitAnimation(bool type);
};


#endif //INC_06_LAB_BATTLESHIP_SQUARE_H
