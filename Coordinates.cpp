//
// Created by Chandler Desforges on 5/31/24.
//

#include "Coordinates.h"

Coordinates::Coordinates() :
row(0),
col(0)
{

}

Coordinates::Coordinates(int row, int col) :
row(row),
col(col)
{

}

Coordinates Coordinates::operator+(const Coordinates &first) const
{
    return {row + first.row, col + first.col};
}

Coordinates Coordinates::operator+(const std::pair<int, int> &first) const
{
    return {row + first.first, col + first.second};
}

Coordinates Coordinates::operator+(const Direction &first) const
{
    return {row + first.row, col + first.col};
}

Coordinates& Coordinates::operator+=(const Coordinates &first)
{
    this->row = this->row + first.row;
    this->col += first.col;
    return *this;
}

Coordinates& Coordinates::operator+=(const std::pair<int, int> &first)
{
    this->row = this->row + first.first;
    this->col += first.second;
    return *this;
}

Coordinates Coordinates::operator*(const int &first) const
{
    return {row * first, col * first};
}

Coordinates Coordinates::operator-(const Coordinates &first) const
{
    return {row - first.row, col - first.col};
}

Coordinates Coordinates::operator-(const std::pair<int, int> &first) const
{
    return {row - first.first, col - first.second};
}

bool Coordinates::operator==(const Coordinates& other) const {
    return (row == other.row && col == other.col);
}

bool Coordinates::operator!=(const Coordinates &other) const
{
    return (row != other.row && col != other.col);
}

bool Coordinates::operator>=(const Coordinates &other) const
{
    return (row >= other.row && col >= other.col);
}

bool Coordinates::operator>=(const std::pair<int, int> &other) const
{
    return (row >= other.first && col >= other.second);
}

Row Coordinates::toRow(int rowIndex)
{
    switch(rowIndex)
    {
        case 0:
            return A;
        case 1:
            return B;
        case 2:
            return C;
        case 3:
            return D;
        case 4:
            return E;
        case 5:
            return F;
        case 6:
            return G;
        case 7:
            return H;
        case 8:
            return I;
        case 9:
            return J;
    }
}

std::pair<int, int> Coordinates::toPair(Coordinates coordinates)
{
    return {coordinates.row, coordinates.col};
}
