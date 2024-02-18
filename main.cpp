#include "geometry.h"
#include "randomizer.h"

#include <algorithm>
#include <exception>
#include <memory>
#include <string_view>
#include <vector>

using namespace std::string_view_literals;

constexpr double T = M_PI / 4;

std::shared_ptr<GeometricCurves> CreateRandomCurve(std::unique_ptr<Randomizer>& rand)
{
    const double rad = rand->GetRandomParameter();
    const double xrad = rand->GetRandomParameter();
    const double yrad = rand->GetRandomParameter();
    const double step = rand->GetRandomParameter();
        
    const int curve_type_init = rand->GetRandomCurveTypeInit();
    switch (curve_type_init)
    {
        case 0:
            return std::make_shared<Circle>(T, rad);
        case 1:
            return std::make_shared<Ellipse>(T, xrad, yrad);
        case 2:
            return std::make_shared<Helix>(T, rad, step);
        default:
            throw std::runtime_error("Invalid curve_type_init generated"); 
    }
}

void PrintInfo(const std::vector<std::shared_ptr<GeometricCurves>>& curves)
{
    for (const auto& curve : curves)
    {
        curve->PrintPointAndVectorInfo(std::cout);
    }
}

int main()
{
    std::unique_ptr<Randomizer> rand = std::make_unique<Randomizer>();
    const int amount = static_cast<int>(rand->GetRandomParameter());

    std::vector<std::shared_ptr<GeometricCurves>> curves;
    curves.reserve(amount);
    for (int i = 0; i < amount; ++i)
    {
        curves.emplace_back(CreateRandomCurve(rand));
    }

    std::cout << "\nRandomly generated geometric curves (generated amount = "sv << amount << "):"sv << std::endl;
    PrintInfo(curves);

    std::vector<std::shared_ptr<GeometricCurves>> circles;
    for (const auto& curve : curves)
    {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve))
        {
            circles.push_back(circle);
        }
    }

    std::sort(circles.begin(), circles.end(),
        [](const std::shared_ptr<GeometricCurves>& lhs, const std::shared_ptr<GeometricCurves>& rhs)
        {
            return lhs->GetRadius() < rhs->GetRadius();
        });
        
    std::cout << "\nCircles from the first container sorted by radius:"sv << std::endl;
    PrintInfo(circles);

    double radii_sum = std::accumulate(circles.begin(), circles.end(), 0.0,
        [](double sum, const std::shared_ptr<GeometricCurves>& circle)
        {
            return sum + circle->GetRadius();
        });

    std::cout << "\nSum of radii of all circles: "sv << radii_sum << std::endl;

    return 0;
}