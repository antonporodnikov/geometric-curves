#pragma once

#include <cmath>
#include <iostream>
#include <string>

using namespace std::string_literals;

class GeometricCurves {
public:
    struct Point {
        double x, y, z;
    };

    struct Vector {
        double x, y, z;
    };

    virtual ~GeometricCurves() = default;
    virtual double GetRadius() const = 0;
    virtual Point GetPoint() const = 0;
    virtual Vector GetFirstDerivative() const = 0;
    virtual void PrintPointAndVectorInfo(std::ostream& output) = 0;
};

class Circle : public GeometricCurves {
public:
    Circle(double t, double rad);

    double GetRadius() const override;
    Point GetPoint() const override;
    Vector GetFirstDerivative() const override;
    void PrintPointAndVectorInfo(std::ostream& output) override;

private:
    double t_, rad_;
};

class Ellipse : public GeometricCurves {
public:
    Ellipse(double t, double xrad, double yrad);

    double GetRadius() const override;
    Point GetPoint() const override;
    Vector GetFirstDerivative() const override;
    void PrintPointAndVectorInfo(std::ostream& output) override;

private:
    double t_, xrad_, yrad_;
};

class Helix : public GeometricCurves {
public:
    Helix(double t, double rad, double step);

    double GetRadius() const override;
    Point GetPoint() const override;
    Vector GetFirstDerivative() const override;
    void PrintPointAndVectorInfo(std::ostream& output) override;

private:
    double t_, rad_, step_;
};