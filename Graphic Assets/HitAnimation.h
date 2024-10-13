//
// Created by Chandler Desforges on 6/3/24.
//

#ifndef INC_06_LAB_BATTLESHIP_HITANIMATION_H
#define INC_06_LAB_BATTLESHIP_HITANIMATION_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "../TextureManager.h"

class HitAnimation : public sf::Drawable
{
private:
    sf::Sprite m_shape;
    sf::Texture* m_explosion;
    Animation m_animation;
    sf::Vector2f m_size;

public:
    HitAnimation();
    HitAnimation(sf::Vector2f size, sf::Vector2f position, bool hit);
    void update(float dt);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //INC_06_LAB_BATTLESHIP_HITANIMATION_H
