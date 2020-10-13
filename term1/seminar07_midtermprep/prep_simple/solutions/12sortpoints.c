#include <stdio.h>
#include <math.h>

struct point
{
	float x, y;
};
typedef struct point Point;

float distance_from_zero(Point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

// Сортировка вставками по последней цифре:
void selection_sort_points(Point array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		// Находим минимальный элемент
		int min_index = i;
		for (int j = i + 1; j < n; j++)
			if (distance_from_zero(array[j]) < distance_from_zero(array[min_index]))
				min_index = j;
				
		// Меняем первый и минимальный
		Point temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
}


int main()
{
	Point points[5] = {{5.2, 3.1}, {7.3, -3.4}, {-1.2, 6.4}, {3.8, 8.7}, {-0.6, 2.1}};

	printf("Before sorting:\n");
	for (int i = 0; i < 5; i++)
		printf("%g %g\n", points[i].x, points[i].y);

	selection_sort_points(points, 5);

	printf("After sorting:\n");
	for (int i = 0; i < 5; i++)
		printf("%g %g\n", points[i].x, points[i].y);
}
