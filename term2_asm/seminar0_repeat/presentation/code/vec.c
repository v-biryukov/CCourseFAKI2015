#include <stdio.h>
#include <math.h>
#include "vec.h"



void init_v3(vec * p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

vec add(vec v, vec u)
{
	vec sum;
	sum.x = v.x + u.x;
	sum.y = v.y + u.y;
	sum.z = v.z + u.z;
	return sum;
}

float scalar_product(vec v, vec u)
{
	float result = v.x*u.x + v.y*u.y + v.z*u.z;
	return result;
}

float len(vec v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

void read(vec * pv)
{
	scanf("%f%f%f", &pv->x, &pv->y, &pv->z);
}

void print(vec v)
{
	printf("(%f, %f, %f)\n", v.x, v.y, v.z);
}
