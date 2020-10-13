#include <stdio.h>
int is_all_divisible_by_7(int* array, int n)
{
	for (int i = 0; i < n; i++)
		if (array[i] % 7 != 0)
			return 0;
	return 1;
}
int main()
{
	int numbers[6] = {7, 56, 777, 119, 14, 378};
	if (is_all_divisible_by_7(numbers, 6))
		printf("Yes, all numbers are divisible by 7\n");
	else
		printf("Not, some numbers are not divisible by 7\n");
}