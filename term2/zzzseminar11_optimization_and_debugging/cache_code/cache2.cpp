#include <cmath>
#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;


#define N 100000


// Протестируйте быстродействие без other_data и с other_data
struct Data
{
	int a;
	int b;
	// int other_data[10];
};


Data* create_random_array()
{
	Data* array = new Data[N];
	for (int index = 0; index < N; ++index)
	{
		array[index].a = rand() % 1000;
		array[index].b = rand() % 1000;
	}
	return array;
}
int main()
{
    Data* array = create_random_array();

    steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (int i = 0; i < N; ++i )
	{
		array[i].a = array[i].b;
	}

	steady_clock::time_point end = std::chrono::steady_clock::now();

	float time = duration_cast<microseconds>(end - begin).count();
	cout << "Total time = " << time << " microseconds" << endl;
	cout << "Time per 1 iteration = " << time / N * 1000 << " nanoseconds" << endl;

	// Задача: проверьте скорость работы программы
	// в зависимости от размера массива other_data в структуктуре Data
	// Почему скорость работы такая?

	return 0;
}