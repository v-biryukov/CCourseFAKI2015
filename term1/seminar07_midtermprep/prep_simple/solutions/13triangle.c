#include <stdio.h>
#include <math.h>

struct point
{
	float x, y;
};
typedef struct point Point;

struct triangle
{
	Point a, b, c;
};
typedef struct triangle Triangle;


float distance(Point a, Point b)
{
	float dx = a.x - b.x;
	float dy = b.x - b.y;
	return sqrt(dx * dx + dy * dy);
}

float perimeter(Triangle t)
{
	return distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);
}

// Лучше передавать структуры по указателю на костанту
float perimeter_by_pointer(const Triangle* t)
{
	return distance(t->a, t->b) + distance(t->b, t->c) + distance(t->c, t->a);
}


Point center_of_mass(Triangle t)
{
	Point result;
	result.x = (t.a.x + t.b.x + t.c.x) / 3;
	result.y = (t.a.y + t.b.y + t.c.y) / 3;
	return result;
}



int main()
{
	Triangle t = {{5.2, 3.1}, {7.3, -3.4}, {-1.2, 6.4}};

	printf("Perimeter = %g\n", perimeter(t));

	Point cm = center_of_mass(t);
	printf("Center of mass = (%g, %g)\n", cm.x, cm.y);
}
