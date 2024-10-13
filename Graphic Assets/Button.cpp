//
// Created by Chandler Desforges on 6/8/24.
//

#include "Button.h"

#include <utility>

Button::Button(unsigned int fontSize, sf::Vector2f position, std::string buttonText) :
m_buttonShape(),
m_textString(std::move(buttonText)),
m_position(position),
m_size((float)fontSize, (float)fontSize),
m_backgroundColor({255,255,255,100})
{
    initializeButton();
}

void Button::initializeButton()
{
    loadFont();

    m_buttonText = sf::Text(m_textString, m_font, (unsigned int)m_size.x);
    m_buttonText.setFillColor(sf::Color::White);
    m_buttonText.setOrigin((m_buttonText.getLocalBounds().left + m_buttonText.getLocalBounds().width) / 2.f, (m_buttonText.getLocalBounds().top + m_buttonText.getLocalBounds().height) / 2.f);
    m_buttonText.setPosition(m_position);
    m_buttonText.setOutlineThickness(2.f);
    m_buttonText.setOutlineColor(sf::Color::Black);

    m_buttonShape.setSize({m_buttonText.getGlobalBounds().width + 40.f, m_buttonText.getGlobalBounds().height + 20.f});
    m_buttonShape.setFillColor(m_backgroundColor);
    m_buttonShape.setOrigin((m_buttonShape.getLocalBounds().left + m_buttonShape.getLocalBounds().width) / 2.f, (m_buttonShape.getLocalBounds().top + m_buttonShape.getLocalBounds().height) / 2.f - 1.f);
    m_buttonShape.setOutlineThickness(5.f);
    m_buttonShape.setOutlineColor(sf::Color::Black);
    m_buttonShape.setPosition(m_position);
}

sf::FloatRect Button::getGlobalBounds()
{
    return m_buttonShape.getGlobalBounds();
}

void Button::setText(const std::string& text)
{
    m_buttonText.setString(text);
}

void Button::setPosition(sf::Vector2f position)
{
    m_buttonText.setPosition(position);
    m_buttonShape.setPosition({m_position.x, m_position.y + 8.f});
}

void Button::setColor(sf::Color color)
{
    m_buttonShape.setFillColor(color);
}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_buttonShape);
    window.draw(m_buttonText);
}

bool Button::contains(const sf::Vector2i &position)
{
    if(getGlobalBounds().left < (float)position.x
       && (float)position.x < getGlobalBounds().left + getGlobalBounds().width)
    {
        if(getGlobalBounds().top < (float)position.y
           && (float)position.y < getGlobalBounds().top + getGlobalBounds().height)
            return true;
    }

    return false;
}

void Button::loadFont()
{
    if(!m_font.loadFromFile("font.ttf"))
        std::cout << "Button class font load error!";
}

void Button::setHoveredState(const bool &tOrF)
{
    if(tOrF)
        setColor(sf::Color(255,255,255,200));
    else
        setColor(m_backgroundColor);
}

void Button::update(sf::RenderWindow &window)
{
    if(contains(sf::Mouse::getPosition(window)))
        setHoveredState(true);
    else
        setHoveredState(false);

    m_buttonText.setString(m_textString);
    m_buttonText.setPosition(m_position);
    m_buttonShape.setPosition({m_position.x, m_position.y + 8.f});
}
