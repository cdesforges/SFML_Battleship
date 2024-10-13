//
// Created by Chandler Desforges on 6/3/24.
//

#include "Animation.h"

Animation::Animation()
{

}

Animation::Animation(sf::Texture &p_texture, sf::Vector2u p_imageCount, float p_switchTime, int numLoops) :
m_imageCount(p_imageCount),
m_switchTime(p_switchTime),
m_totalTime(0.0f),
m_numLoops(numLoops)
{
    m_currentImage.x = 0;
    m_currentImage.y = 0;
    m_currentLoop = 0;

    m_textureRect.width = (int)((float)p_texture.getSize().x / (float)m_imageCount.x);
    m_textureRect.height = (int)((float)p_texture.getSize().y / (float)m_imageCount.y);
}

void Animation::update(float p_dt)
{
    m_totalTime += p_dt;

    if(m_totalTime >= m_switchTime)
    {
        m_totalTime -= m_switchTime;
        m_currentImage.x++;

        if(m_currentImage.x >= m_imageCount.x && m_numLoops == 0)
        {
            m_currentImage.x = 0;
            m_currentImage.y++;

            if(m_currentImage.y >= m_imageCount.y)
            {
                m_currentImage.y = 0;
            }
        }
        else if(m_currentImage.x >= m_imageCount.x && m_currentLoop < m_numLoops - 1)
        {
            m_currentLoop++;
            m_currentImage.x = 0;
            m_currentImage.y++;

            if(m_currentImage.y >= m_imageCount.y)
            {
                m_currentImage.y = 0;
            }
        }
        else if(m_currentImage.x >= m_imageCount.x && m_currentLoop == m_numLoops - 1)
            m_currentImage = m_imageCount;
    }

    m_textureRect.left = (int)m_currentImage.x * m_textureRect.width;
    m_textureRect.top = (int)m_currentImage.y * m_textureRect.height;
}
