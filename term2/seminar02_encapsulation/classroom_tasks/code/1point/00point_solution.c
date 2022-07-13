/*
    Это программа на языке C, для компиляции:
        gcc 00point_solution.c
        ./a.out
*/

#include <stdio.h>
#include <math.h>


struct point 
{
    float x, y;
};
typedef struct point Point;


void point_print(Point a)
{
    printf("(%.2f, %.2f)\n", a.x, a.y);
}

Point point_add(Point a, Point b)
{
    Point result = {a.x + b.x, a.y + b.y};
    return result;
}

float point_norm(Point a)
{
    return sqrtf(a.x * a.x + a.y * a.y);
}

Point point_mult(Point a, float k)
{
    Point result = {k * a.x, k * a.y};
    return result;
}

void point_normalize(Point* pa)
{
    float norm = point_norm(*pa);
    pa->x /= norm;
    pa->y /= norm;
}


int main() 
{
    Point a = {7.2, 3.1};
    Point b = {-4.6, 2.4};
    
    point_print(a);
    point_print(b);

    Point c = point_add(a, b);
    point_print(c);

    point_print(point_mult(c, 1.5f));

    point_normalize(&c);
    point_print(c);
}