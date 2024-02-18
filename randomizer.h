#pragma once

#include <random>

class Randomizer {
public:
    Randomizer();
    ~Randomizer() = default;

    double GetRandomParameter();
    int GetRandomCurveTypeInit();

private:
    std::random_device rd_;
    std::mt19937 gen_;
};