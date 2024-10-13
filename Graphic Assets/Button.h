//
// Created by Chandler Desforges on 6/8/24.
//

#ifndef INC_06_LAB_BATTLESHIP_BUTTON_H
#define INC_06_LAB_BATTLESHIP_BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button : public sf::Drawable
{
private:
    sf::RectangleShape m_buttonShape;
    sf::Text m_buttonText;
    sf::Font m_font;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    std::string m_textString;
    sf::Color m_backgroundColor;

public:
    Button(unsigned int fontSize, sf::Vector2f position, std::string buttonText);
    ~Button() override = default;
    void initializeButton();

    // getters
    sf::FloatRect getGlobalBounds();

    // setters
    void setText(const std::string& text);
    void setPosition(sf::Vector2f position);
    void setColor(sf::Color color);
    void setHoveredState(const bool &tOrF);

    // functions
    bool contains(const sf::Vector2i &position);
    void loadFont();
    void update(sf::RenderWindow &window);

    //inherited
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;

};


#endif //INC_06_LAB_BATTLESHIP_BUTTON_H
