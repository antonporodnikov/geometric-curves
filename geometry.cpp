#include "geometry.h"

Circle::Circle(double t, double rad) : t_(t), rad_(rad) {}

double Circle::GetRadius() const
{
    return rad_;
}

GeometricCurves::Point Circle::GetPoint() const
{   
    return Point{rad_ * std::cos(t_), rad_ * std::sin(t_), 0};
}

GeometricCurves::Vector Circle::GetFirstDerivative() const
{
    Point point = this->GetPoint();

    double tangent_x = -point.y;
    double tangent_y = point.x;
    double tangent_z = 0.0;

    double magnitude = std::sqrt(tangent_x * tangent_x + tangent_y * tangent_y + tangent_z * tangent_z);
    tangent_x /= magnitude;
    tangent_y /= magnitude;
    tangent_z /= magnitude;

    return Vector{tangent_x, tangent_y, tangent_z};
}

void Circle::PrintPointAndVectorInfo(std::ostream& output)
{
    Point point = this->GetPoint();
    Vector vector = this->GetFirstDerivative();

    output << "Circle (Radius = "s << rad_
        << ") - Point ["s << point.x << ", "s << point.y << ", "s << point.z
        << "], Vector ["s << vector.x << ", "s << vector.y << ", "s << vector.z << "]\n"s;
}

Ellipse::Ellipse(double t, double xrad, double yrad) : t_(t), xrad_(xrad), yrad_(yrad) {}

double Ellipse::GetRadius() const
{
    return xrad_;
}

GeometricCurves::Point Ellipse::GetPoint() const
{
    return Point{xrad_ * std::cos(t_), yrad_ * std::sin(t_), 0};
}

GeometricCurves::Vector Ellipse::GetFirstDerivative() const
{
    double tangent_x = -xrad_ * std::sin(t_);
    double tangent_y = yrad_ * std::cos(t_);
    double tangent_z = 0.0;

    double magnitude = std::sqrt(tangent_x * tangent_x + tangent_y * tangent_y + tangent_z * tangent_z);
    tangent_x /= magnitude;
    tangent_y /= magnitude;
    tangent_z /= magnitude;

    return Vector{tangent_x, tangent_y, tangent_z};
}

void Ellipse::PrintPointAndVectorInfo(std::ostream& output)
{
    Point point = this->GetPoint();
    Vector vector = this->GetFirstDerivative();

    output << "Ellipse (XRadius = "s << xrad_ << ", YRadius = "s << yrad_
        << ") - Point ["s << point.x << ", "s << point.y << ", "s << point.z
        << "], Vector ["s << vector.x << ", "s << vector.y << ", "s << vector.z << "]\n"s;
}


Helix::Helix(double t, double rad, double step) : t_(t), rad_(rad), step_(step) {}

double Helix::GetRadius() const
{
    return rad_;
}

GeometricCurves::Point Helix::GetPoint() const
{
    return Point{rad_ * std::cos(t_), rad_ * std::sin(t_), step_ * t_ / (2 * M_PI)};
}

GeometricCurves::Vector Helix::GetFirstDerivative() const
{
    double tangent_x = -rad_ * std::sin(t_);
    double tangent_y = rad_ * std::cos(t_);
    double tangent_z = step_ / (2 * M_PI);

    double magnitude = std::sqrt(tangent_x * tangent_x + tangent_y * tangent_y + tangent_z * tangent_z);
    tangent_x /= magnitude;
    tangent_y /= magnitude;
    tangent_z /= magnitude;

    return Vector{tangent_x, tangent_y, tangent_z};
}

void Helix::PrintPointAndVectorInfo(std::ostream& output)
{
    Point point = this->GetPoint();
    Vector vector = this->GetFirstDerivative();

    output << "Helix (Radius = "s << rad_ << ", Step = "s << step_
        << ") - Point ["s << point.x << ", "s << point.y << ", "s << point.z
        << "], Vector ["s << vector.x << ", "s << vector.y << ", "s << vector.z << "]\n"s;
}