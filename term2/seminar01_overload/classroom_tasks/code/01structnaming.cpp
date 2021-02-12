#include <cstdio>

struct Date
{
	int day, month, year;
};
// В языке C, при таком определении структуры,
// создастся новый тип по имени struct Date
// Чтобы использовать более удобное имя мы использовали typedef

// В языке C++ автоматически создастся тип Date (typedef писать не нужно)

int main()
{
	Date a = {5, 5, 1990};
	printf("%d.%d.%d\n", a.day, a.month, a.year);
}