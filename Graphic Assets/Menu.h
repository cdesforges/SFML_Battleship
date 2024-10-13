//
// Created by Chandler Desforges on 5/1/24.
//

#ifndef INC_06_LAB_BATTLESHIP_MENU_H
#define INC_06_LAB_BATTLESHIP_MENU_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <mach-o/dyld.h>
#include <fstream>

class Menu : public sf::Drawable
{
private:
    sf::Text m_menuText;
    sf::Font m_retro;

public:
    Menu() = default;
    Menu(const std::string& menuText, sf::Vector2f position, int fontSize);
    void loadFont(const std::string& fontLocation);
    sf::Text getText();
    void setText(const std::string& newText);
    void update();
    void draw(sf::RenderTarget &window, sf::RenderStates states) const override;
};


#endif //INC_06_LAB_BATTLESHIP_MENU_H
