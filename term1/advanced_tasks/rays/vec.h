#include <iostream>
#include <cmath>

struct vec3
{
	float x, y, z;
};

vec3 operator+(vec3 left, vec3 right)
{
	vec3 result = {left.x + right.x, left.y + right.y, left.z + right.z};
	return result;
}

vec3 operator-(vec3 left, vec3 right)
{
	vec3 result = {left.x - right.x, left.y - right.y, left.z - right.z};
	return result;
}

vec3 operator*(float a, vec3 right)
{
	vec3 result = {a * right.x, a * right.y, a * right.z};
	return result;
}

vec3 operator*(vec3 left, float a)
{
	vec3 result = {a * left.x, a * left.y, a * left.z};
	return result;
}

vec3 operator/(vec3 left, float a)
{
	vec3 result = {left.x / a, left.y / a, left.z / a};
	return result;
}

float operator*(vec3 left, vec3 right)
{
	float result = left.x * right.x + left.y * right.y + left.z * right.z;
	return result;
}

float norm(vec3 v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}


std::ostream& operator<<(std::ostream& stream, vec3 right)
{
	stream << "(" << right.x << ", " << right.y << ", " << right.z << ")";
	return stream;
}