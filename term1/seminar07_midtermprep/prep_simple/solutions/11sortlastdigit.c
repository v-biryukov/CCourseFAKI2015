#include <stdio.h>
// Сортировка вставками по последней цифре:
void selection_sort_last_digit(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		// Находим минимальный элемент
		int min_index = i;
		for (int j = i + 1; j < n; j++)
			if (array[j] % 10 < array[min_index] % 10)
				min_index = j;
				
		// Меняем первый и минимальный
		int temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
}
int main()
{
	int numbers[10] = {54, 76, 83, 26, 17, 95, 43, 6, 54, 61};
	selection_sort_last_digit(numbers, 10);
	for (int i = 0; i < 10; i++)
		printf("%d ", numbers[i]);
}