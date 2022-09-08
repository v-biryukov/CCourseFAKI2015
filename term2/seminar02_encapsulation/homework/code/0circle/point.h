#pragma once

/*
    Поля x и y сделаны приватными
    Конкретно для этого класса их можно было сделать публичными
    Так как пользователь всё-равно будет иметь доступ без ограничений к этим полям через геттеры и сеттеры
    Но они сделаны приватными для образовательных целей
*/

class Point
{
private:
    float mx, my;
    
public:

    Point(float x, float y);
    Point();

    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    void normalize();
    float distance(const Point& p) const;
    float norm() const;
    Point operator+(const Point& right) const;
    Point operator*(float a) const;



    friend Point operator*(float a, const Point& p);
    friend std::ostream& operator<<(std::ostream& left, const Point& right);
};


