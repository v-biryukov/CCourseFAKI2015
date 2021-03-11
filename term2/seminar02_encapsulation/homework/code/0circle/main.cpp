#include <iostream>
#include "point.h"

using namespace std;

class Circle
{
private:
	Point center;
	float radius;

public:


};

int main()
{
	Point p = {7, -1};
	Point q = {-4, 2};
	cout << "Point p = " << p << endl;
	cout << "Point q = " << q << endl;
	cout << "p + q = " << p + q << endl;

/*
	Circle a {{4, 1}, 3};
	Circle b;

	cout << "Circle a: center: " << a.get_center() << " radius: " << a.get_radius() << endl; 
	cout << "Circle b: center: " << b.get_center() << " radius: " << b.get_radius() << endl;

	cout << "Area of a = " << a.get_area() << endl;
	cout << "Distance from point p to circle a = " << a.get_distance(p) << endl;



	cout << "Collisions:" << endl;
	if (a.is_colliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;



	cout << "Moving b by {1, 1}:" << endl;
	b.move({1, 1});
	if (a.is_colliding(b))
		cout << "Yes, a is colliding b" << endl;
	else
		cout << "No, a isn't colliding b" << endl;
*/


}