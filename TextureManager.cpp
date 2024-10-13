//
// Created by Chandler Desforges on 6/10/24.
//

#include "TextureManager.h"

std::map<std::string, sf::Texture> TextureManager::m_allTextures;

sf::Texture &TextureManager::getTexture(const ShipType& shipType)
{
    std::string fileName = getFileName(shipType);

    auto it = m_allTextures.find(fileName);

    if(it != m_allTextures.end())
        return it->second;

    sf::Texture texture;
    if(!texture.loadFromFile(fileName))
        throw std::runtime_error("Failed to load texture from file! " + fileName);

    auto inserted = m_allTextures.insert(std::make_pair(fileName, std::move(texture)));
    return inserted.first->second;
}

sf::Texture &TextureManager::getTexture(const std::string &filePath)
{
    auto it = m_allTextures.find(filePath);

    if(it != m_allTextures.end())
        return it->second;

    sf::Texture texture;
    if(!texture.loadFromFile(filePath))
        throw std::runtime_error("Failed to load texture from file! " + filePath);

    auto inserted = m_allTextures.insert(std::make_pair(filePath, std::move(texture)));
    return inserted.first->second;
}

std::string TextureManager::getFileName(const ShipType &shipType)
{
    switch(shipType)
    {
        case DESTROYER:
            return "ShipDestroyer.png";
        case SUBMARINE:
            return "ShipSubmarine.png";
        case JEFF:
            return "ShipJeff.png";
        case BATTLESHIP:
            return "ShipBattleship.png";
        case CARRIER:
            return "ShipCarrier.png";
    }
}
