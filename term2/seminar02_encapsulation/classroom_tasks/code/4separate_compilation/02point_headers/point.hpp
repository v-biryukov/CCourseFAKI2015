#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

struct Point 
{
    float x, y;

    Point operator+(Point b) const
    {
        Point result = {x + b.x, y + b.y};
        return result;
    }

    float norm() const
    {
        return std::sqrt(x * x + y * y);
    }

    Point operator*(float k) const
    {
        Point result = {k * x, k * y};
        return result;
    }

    void normalize()
    {
        float normv = norm();
        x /= normv;
        y /= normv;
    }
};

std::ostream& operator<<(std::ostream& out, Point a)
{
    out << std::setprecision(2) << "(" << a.x << ", " << a.y << ")";
    return out;
}