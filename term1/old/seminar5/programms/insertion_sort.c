#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int array[100];
	for (int i = 0; i < n; ++i)
		scanf("%d", &array[i]);

	int i, j, current;
	for (i = 1; i < n; i++) {
        current = array[i];
        for (j = i; j > 0 && current < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }
        array[j] = current;
    }
    for (int i = 0; i < n; ++i)
		printf("%d ", array[i]);

}