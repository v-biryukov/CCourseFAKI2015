#pragma once
#include <iostream>


struct Point 
{
    float x, y;

    Point operator+(Point b) const;
    float norm() const;
    Point operator*(float k) const;
    void normalize();
};

std::ostream& operator<<(std::ostream& out, Point a);
