#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979
#define DEG_TO_RAD (M_PI / 180)

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


void move(Triangle* pt, Point r)
{
	pt->a.x += r.x;
	pt->b.x += r.x;
	pt->c.x += r.x;

	pt->a.y += r.y;
	pt->b.y += r.y;
	pt->c.y += r.y;
}

void rotate_point(Point* p, float angle)
{
	Point result;
	result.x = p->x * cos(DEG_TO_RAD * angle) - p->y * sin(DEG_TO_RAD * angle);
	result.y = p->x * sin(DEG_TO_RAD * angle) + p->y * cos(DEG_TO_RAD * angle);
	p->x = result.x;
	p->y = result.y;
}

void rotate(Triangle* pt, float angle)
{
	rotate_point(&pt->a, angle);
	rotate_point(&pt->b, angle);
	rotate_point(&pt->c, angle);
}

void print_triangle(Triangle t)
{
	printf("Triangle: a = (%g, %g)  b = (%g, %g)  c = (%g, %g)\n", t.a.x, t.a.y, t.b.x, t.b.y, t.c.x, t.c.y);
}


int main()
{
	Triangle t = {{5.2, 3.1}, {7.3, -3.4}, {-1.2, 6.4}};
	print_triangle(t);

	printf("Moving by (1, 2):\n");
	Point delta = {1, 2};
	move(&t, delta);
	print_triangle(t);

	printf("Rotating by 30 degree around (0, 0):\n");
	rotate(&t, 30);
	print_triangle(t);
}
