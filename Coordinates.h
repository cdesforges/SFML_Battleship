//
// Created by Chandler Desforges on 5/31/24.
//

#ifndef INC_06_LAB_BATTLESHIP_COORDINATES_H
#define INC_06_LAB_BATTLESHIP_COORDINATES_H

#include "Enums.h"
#include <vector>
#include "Direction.h"

class Coordinates
{
public:
    int row;
    int col;

    Coordinates();
    Coordinates(int row, int col);
    Coordinates operator+(const Coordinates &first) const;
    Coordinates operator+(const std::pair<int, int> &first) const;
    Coordinates operator+(const Direction &first) const;
    Coordinates& operator+=(const Coordinates &first);
    Coordinates& operator+=(const std::pair<int, int> &first);
    Coordinates operator*(const int &first) const;
    Coordinates operator-(const Coordinates &first) const;
    Coordinates operator-(const std::pair<int, int> &first) const;
    bool operator==(const Coordinates& other) const;
    bool operator!=(const Coordinates& other) const;
    bool operator>=(const Coordinates& other) const;
    bool operator>=(const std::pair<int, int>& other) const;
    static std::pair<int, int> toPair(Coordinates coordinates);

    static Row toRow(int rowIndex);
};


#endif //INC_06_LAB_BATTLESHIP_COORDINATES_H
