//
// Created by Chandler Desforges on 6/10/24.
//

#ifndef INC_06_LAB_BATTLESHIP_TEXTUREMANAGER_H
#define INC_06_LAB_BATTLESHIP_TEXTUREMANAGER_H

#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include "Enums.h"

class TextureManager
{
private:
    static std::map<std::string, sf::Texture> m_allTextures;
    static std::string getFileName(const ShipType& shipType);

public:
    static sf::Texture& getTexture(const ShipType& shipType);
    static sf::Texture& getTexture(const std::string& filePath);
};


#endif //INC_06_LAB_BATTLESHIP_TEXTUREMANAGER_H
