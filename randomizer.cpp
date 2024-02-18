#include "randomizer.h"

Randomizer::Randomizer() : rd_(), gen_(rd_()) {}

double Randomizer::GetRandomParameter()
{
    std::uniform_real_distribution<double> urd(0.1, 100);
    return urd(gen_);
}

int Randomizer::GetRandomCurveTypeInit()
{
    std::uniform_int_distribution<int> unt(0, 2);
    return unt(gen_);
}