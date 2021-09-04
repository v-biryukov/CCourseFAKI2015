#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;

// Размеры квадратной матрицы M на N
// Меняйте M и N и посмотрите как меняется время выполнения программы
#define M 10000
#define N 10000

// Функция, которая создаёт матрицу случайных вещественных чисел в куче
// Все числа от 0 до 1
float* create_random_array()
{
	float* array = new float[N * M];
	for (int index = 0; index < N * M; ++index)
	{
		array[index] = (float)rand() / RAND_MAX;
	}
	return array;
}


// Две функции, которые складывают двумерные матрицы
// Какая из них будет работать быстрее? sum_array_rows или sum_array_colums
float sum_array_rows(float* a)
{
	int i, j;
	float sum = 0.0f;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			sum += a[i + j * M];
	return sum;
}


float sum_array_colums(float* a)
{
	int i, j;
	float sum = 0.0f;
	for (j = 0; j < N; j++)
		for (i = 0; i < M; i++)
			sum += a[i + j * M];
	return sum;
}




int main()
{
	// Создаём случайную матрицу M на N
	float* a = create_random_array();

	// Теперь попробуем найти сумму двумя разными функциями

	// Засекаем время с помощью библиотеки chrono
	steady_clock::time_point begin = std::chrono::steady_clock::now();
	// Вычисляем сумму, с помощью первой функции
	float sum = sum_array_rows(a);
	// Засекаем время ещё раз и печатаем результаты
	steady_clock::time_point end = std::chrono::steady_clock::now();
	cout << "Sum = " << sum << endl;
	cout << "Time to calculate the sum = " << duration_cast<microseconds>(end - begin).count() << " microseconds" << endl;

	// Проделываем то же самое со второй функцией
	begin = std::chrono::steady_clock::now();
	float sum2 = sum_array_colums(a);
	end = std::chrono::steady_clock::now();
	cout << "Sum = " << sum2 << endl;
	cout << "Time to calculate the sum = " << duration_cast<microseconds>(end - begin).count() << " microseconds" << endl;
	
	delete [] a;
	return 0;
}