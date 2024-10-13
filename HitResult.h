//
// Created by Chandler Desforges on 6/15/24.
//

#ifndef INC_06_LAB_BATTLESHIP_HITRESULT_H
#define INC_06_LAB_BATTLESHIP_HITRESULT_H

#include "Coordinates.h"
#include "Enums.h"

struct HitResult
{
    Coordinates coordinates;
    ShipType shipType;
    int shipHealth;

    HitResult()
    {
        coordinates = {-1,-1};
        shipType = EMPTY;
        shipHealth = -1;
    }

    std::string displayHitResult()
    {
        std::string shipTypeString;

        switch(shipType)
        {
            case DESTROYER:
                shipTypeString = "Destroyer";
                break;
            case SUBMARINE:
                shipTypeString = "Submarine";
                break;
            case JEFF:
                shipTypeString = "Jeff";
                break;
            case BATTLESHIP:
                shipTypeString = "Battleship";
                break;
            case CARRIER:
                shipTypeString = "Carrier";
                break;
            case EMPTY:
                shipTypeString = "Empty";
                break;
        }

        std::cout << "Hit result | Coordinates: " << coordinates.row << ", " << coordinates.col << "\tShip type: " << shipTypeString << "\tHealth: " << shipHealth << std::endl;
    }
};


#endif //INC_06_LAB_BATTLESHIP_HITRESULT_H
