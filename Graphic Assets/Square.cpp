//
// Created by Chandler Desforges on 5/31/24.
//

#include "Square.h"

sf::Texture Square::m_texture;
sf::Font Square::m_font;

Square::Square(const float &size, const sf::Vector2f &position, const sf::Color &color, Coordinates coordinates) :
m_coordinates(coordinates),
m_shipPointer(nullptr),
m_color(sf::Color::White)
{
    if(!m_font.loadFromFile("Arial.ttf"))
        std::cout << "Couldn't load font!";

    if(!m_texture.loadFromFile("ocean.png"))
    {
        std::cout << "Texture load failed!\n";
    }

    m_shape.setScale({1.5, 1.5});
    m_shape.setTexture(m_texture);

    m_animation = Animation(m_texture, sf::Vector2u(8, 2), 0.2f, 0);

    m_shape.setPosition(position);

    m_debugText.setString(" ");
    m_debugText.setPosition(position);
    m_debugText.setFont(m_font);
    m_debugText.setCharacterSize(20); // in pixels, not points!
    m_debugText.setFillColor(m_color);
    m_debugText.setStyle(sf::Text::Bold);
}

void Square::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_shape);
//    window.draw(m_debugText);
    for(auto& explosion: m_explosions)
        window.draw(explosion);
}

sf::Sprite& Square::getShape()
{
    return m_shape;
}

void Square::setFillColor(const sf::Color &color)
{
    m_color = color;
//    if(color == sf::Color::White)
//        std::cout << "SetFillColor made m_color to white\n";
//    if(color == sf::Color::Red)
//        std::cout << "SetFillColor made m_color to red\n";
}

HitResult Square::attack()
{
    // default constructor is miss
    HitResult result;

    // if there's a ship there
    if(m_shipPointer != nullptr)
    {
        m_color = sf::Color::Red;
        std::cout << "Set color to red\n";
        m_shipPointer->missileHit();
        hitAnimation(true);
        result.coordinates = m_coordinates;
        result.shipType = m_shipPointer->getShipType();
        result.shipHealth = m_shipPointer->getHealth();
        return result;
    }
    else
    {
        m_color = sf::Color::Green;
        hitAnimation(false);
        return result;
    }
}

void Square::hitAnimation(bool type)
{
    m_explosions.emplace_back(sf::Vector2f(10.f,10.f), getShape().getPosition(), type);
}

bool Square::isHovered(const sf::RenderWindow &window)
{
    if((float)sf::Mouse::getPosition(window).x > m_shape.getGlobalBounds().left
       && (float)sf::Mouse::getPosition(window).x < m_shape.getGlobalBounds().left + m_shape.getGlobalBounds().width)
    {
        if((float)sf::Mouse::getPosition(window).y > m_shape.getGlobalBounds().top
           && (float)sf::Mouse::getPosition(window).y < m_shape.getGlobalBounds().top + m_shape.getGlobalBounds().height)
        {
            return true;
        }
    }

    return false;
}

bool Square::containsPosition(const sf::Vector2f &position)
{
    if(m_shape.getGlobalBounds().contains(position))
        return true;
    else
        return false;
}

void Square::setShipPtr(const std::shared_ptr<Ship>& ship)
{
    m_shipPointer = ship;
    std::cout << "Assigning ship pointer: " << ship.get() << " to square at " << m_coordinates.row << ", " << m_coordinates.col << "\n";
    switch (ship->getShipType())
    {
        case DESTROYER:
            m_debugText.setString("D");
            break;
        case SUBMARINE:
            m_debugText.setString("S");
            break;
        case JEFF:
            m_debugText.setString("J");
            break;
        case BATTLESHIP:
            m_debugText.setString("B");
            break;
        case CARRIER:
            m_debugText.setString("C");
            break;
    }
}

Coordinates Square::getCoordinates()
{
    return m_coordinates;
}

void Square::update(float dt)
{
    m_animation.update(dt);
    m_shape.setTextureRect(m_animation.m_textureRect);
    m_shape.setColor(m_color);
    for(auto& explosion : m_explosions)
        explosion.update(dt);
}

std::shared_ptr<Ship> Square::getShipPtr()
{
    return m_shipPointer;
}

void Square::setDebugText(int index)
{
    if(index < 10)
    {
        m_debugText.setString(std::to_string(index));
    }
    else
        m_debugText.setString(" ");

}

void Square::setDebugText(std::string string)
{
    m_debugText.setString(string);
}

sf::Color Square::getFillColor()
{
    return m_color;
}
