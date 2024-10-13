//
// Created by Chandler Desforges on 6/3/24.
//

#include "HitAnimation.h"

HitAnimation::HitAnimation()
{}

HitAnimation::HitAnimation(sf::Vector2f size, sf::Vector2f position, bool hit) :
m_size(size)
{
    if(hit)
    {
        m_explosion = &TextureManager::getTexture("explosion.png");
        m_shape.setScale({1.5,1.5});
        m_animation = Animation(*m_explosion, sf::Vector2u(6,1), 0.06f, 1);
        m_shape.setTexture(*m_explosion);
    }
    else
    {
        m_explosion = &TextureManager::getTexture("splash.png");
        m_shape.setScale({1.5,1.5});
        m_animation = Animation(*m_explosion, sf::Vector2u(8,1), 0.05f, 1);
        m_shape.setTexture(*m_explosion);
    }

    m_shape.setPosition(position);
}

void HitAnimation::update(float dt)
{
    m_animation.update(dt);
    m_shape.setTextureRect(m_animation.m_textureRect);
}

void HitAnimation::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(m_shape);
}
