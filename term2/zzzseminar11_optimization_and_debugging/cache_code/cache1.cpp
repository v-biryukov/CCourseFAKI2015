#include <cmath>
#include <cstdlib>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;

// Протестируйте работу программы с различными значениями N
// Постройте график время работы от N
#define N 1000000000

float* create_random_array()
{
	float* array = new float[N];
	for (int index = 0; index < N; ++index)
	{
		array[index] = (float)rand() / RAND_MAX;
	}
	return array;
}

int main()
{
	float* array = create_random_array();


	steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (int k = 0; k < 100; ++k)
		for (int i = 0; i < N / 2; ++i)
		{
			float temp = array[i];
			array[i] = array[N - 1 - i];
			array[N - 1 - i] = temp;
		}
	steady_clock::time_point end = std::chrono::steady_clock::now();

	float time = duration_cast<microseconds>(end - begin).count();
	cout << "Total time = " << time << " microseconds" << endl;
	cout << "Time per 1 iteration = " << time / N * 1000 << " nanoseconds" << endl;
	delete [] array;
	return 0;
}