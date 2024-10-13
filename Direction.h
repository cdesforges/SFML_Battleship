//
// Created by Chandler Desforges on 6/15/24.
//

#ifndef INC_06_LAB_BATTLESHIP_DIRECTION_H
#define INC_06_LAB_BATTLESHIP_DIRECTION_H


struct Direction
{
    int row;
    int col;

    Direction() = default;
    Direction(int row, int col) : row(row), col(col) {}

    Direction operator*(const int& i) const
    {
        return {row * i, col * i};
    }
};


#endif //INC_06_LAB_BATTLESHIP_DIRECTION_H
