//
// Created by Chandler Desforges on 6/3/24.
//

#ifndef INC_06_LAB_BATTLESHIP_ANIMATION_H
#define INC_06_LAB_BATTLESHIP_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Animation
{

private:
    sf::Vector2u m_imageCount;
    sf::Vector2u m_currentImage;
    float m_totalTime;
    float m_switchTime;
    int m_numLoops;
    int m_currentLoop;

public:
    sf::IntRect m_textureRect;

public:
    Animation();
    Animation(sf::Texture &p_texture, sf::Vector2u p_imageCount, float p_switchTime, int numLoops);
    void update(float dt);


};


#endif //INC_06_LAB_BATTLESHIP_ANIMATION_H
