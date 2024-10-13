//
// Created by Chandler Desforges on 6/7/24.
//

#ifndef INC_06_LAB_BATTLESHIP_RAND_H
#define INC_06_LAB_BATTLESHIP_RAND_H

#include <iostream>
#include <random>
#include <chrono>

class Rand
{
public:
    // Public function to seed the random number generator
    static void seed();

    // Static method to get a random integer within a range
    static int rint(int min, int max);

    // Static method to get a random float within a range
    static float rfloat(float min, float max);

    static std::mt19937& getRng();

private:
    // Random number generator
    static std::mt19937 rng;

    // Seed generator function
    static std::mt19937::result_type seedGenerator();
};


#endif //INC_06_LAB_BATTLESHIP_RAND_H
