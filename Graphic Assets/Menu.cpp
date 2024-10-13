//
// Created by Chandler Desforges on 5/1/24.
//

#include "Menu.h"

Menu::Menu(const std::string& menuText, sf::Vector2f position, int fontSize)
{

    loadFont("font.ttf");
    m_menuText.setString(menuText);
    m_menuText.setFont(m_retro);
    m_menuText.setCharacterSize(fontSize); // in pixels, not points!
    m_menuText.setFillColor(sf::Color::White);
    m_menuText.setOutlineColor(sf::Color::Black);
    m_menuText.setOutlineThickness(5.f);
    m_menuText.setStyle(sf::Text::Bold);
    m_menuText.setOrigin(m_menuText.getGlobalBounds().width / 2.f, m_menuText.getGlobalBounds().height / 2.f);
    m_menuText.setPosition(position);
}

void Menu::loadFont(const std::string& fontLocation)
{
    if(!m_retro.loadFromFile(fontLocation))
        std::cout << "Couldn't load font!";
}

sf::Text Menu::getText()
{
    return m_menuText;
}

void Menu::update()
{
    // make this later if need be
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_menuText);
}

void Menu::setText(const std::string &newText)
{
    m_menuText.setString(newText);
}
