#include "MathsHelper.h"

//I'm sure you've seen this somewhere before (Credits to the lecturer that wrote this function)
std::random_device device;
std::mt19937 randomGenerator(device());

int random(int min, int max)
{

    int trueMin = std::min(min, max);
    int trueMax = std::max(max, min);

    std::uniform_int_distribution<int> udist(trueMin, trueMax);

    return udist(randomGenerator);
}
