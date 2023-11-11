/*
    Класс точки
*/
#pragma once

class Point
{
private:
    float mx, my;
    
public:
    Point();
    Point(float x, float y);
    
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    void normalize();
    float distance(Point p) const;
    float norm() const;
    Point operator+(Point right) const;
    Point operator*(float a) const;


    friend Point operator*(float a, Point p);
    friend std::ostream& operator<<(std::ostream& left, Point right);
};


