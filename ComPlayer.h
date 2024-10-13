//
// Created by Chandler Desforges on 6/6/24.
//

#ifndef INC_06_LAB_BATTLESHIP_COMPLAYER_H
#define INC_06_LAB_BATTLESHIP_COMPLAYER_H

#include "Board.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ComAI.h"

class ComPlayer : public Player
{
private:
    ComAI m_comAI;

public:
    ComPlayer(Player& playingAgainst);
    ~ComPlayer() override = default;

    void move();

};


#endif //INC_06_LAB_BATTLESHIP_COMPLAYER_H
