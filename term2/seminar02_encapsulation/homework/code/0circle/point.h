#pragma once


// Поля x и y сделаны приватными
// Конкретно для этого класса их можно было сделать публичными
// Так как пользователь всё-равно будет иметь доступ без ограничений 
// к этим полям через геттеры и сеттеры
// Но они сделаны приватными для образовательных целей

class Point
{
private:
	float x, y;
	
public:
	// Конструкторы:
	Point(float x, float y);
	Point();
	// Методы класса
	float get_x() const;
	float get_y() const;
	void set_x(float x);
	void set_y(float y);

	void normalize();
	float distance(const Point& p) const;
	float norm() const;
	Point operator+(const Point& right) const;
	Point operator*(float a) const;

	// Прототипы дружественных функций:
	// Дружественные функции - это обычные функции (а не методы),
	// которые имеют доступ к приватной части класса
	friend Point operator*(float a, const Point& p);
	friend std::ostream& operator<<(std::ostream& left, const Point& right);
};


