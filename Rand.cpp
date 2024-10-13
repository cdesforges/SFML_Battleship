//
// Created by Chandler Desforges on 6/7/24.
//

#include "Rand.h"

std::mt19937 Rand::rng;

void Rand::seed()
{
    rng.seed(seedGenerator());
}

int Rand::rint(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

float Rand::rfloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

std::mt19937::result_type Rand::seedGenerator()
{
    auto now = std::chrono::high_resolution_clock::now();
    auto seed = now.time_since_epoch().count();
    return static_cast<std::mt19937::result_type>(seed);
}

std::mt19937 &Rand::getRng()
{
    return rng;
}
