#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;

#define N 2000
#define B 50


// Функция, которая создаёт матрицу случайных вещественных чисел NxN в куче
// Все числа от 0 до 1
double* create_random_array()
{
	double* array = new double[N * N];
	for (int index = 0; index < N * N; ++index)
	{
		array[index] = (double)rand() / RAND_MAX;
	}
	return array;
}


void mat_mult_ijk(double* a, double* b, double* c)
{
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			double sum = 0.0;
			for (int k = 0; k < N; k++)
				sum += a[i * N + k] * b[k * N + j];
			c[i * N + j] = sum;
		}
	}
}

void mat_mult_kij(double* a, double* b, double* c)
{
	
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			c[i * N + j] = 0;
		}
	}

	for (int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			double r = a[i * N + k];
			for (int j = 0; j < N; j++)
				c[i * N + j] += r * b[k * N + j];
		}
	}
}


void mat_mult_block(double* a, double* b, double* c)
{
	for (int i = 0; i < N; i += B)
	{
		for (int j = 0; j < N; j += B)
		{
			for (int k = 0; k < N; k += B)
			{
				for (int i1 = i; i1 < i+B; i1++)
					for (int j1 = j; j1 < j+B; j1++)
					{
						double sum = 0.0;
						for (int k1 = k; k1 < k+B; k1++)
							sum += a[i1*N + k1] * b[k1*N + j1];
						c[i1*N + j1] = sum;
					}
			}
		}
	}
}




// Протестируйте разные функции умножения матриц
// С разными N и B(для mat_mult_block)

int main()
{
	double* a = create_random_array();
	double* b = create_random_array();
	double* c = create_random_array();


	steady_clock::time_point begin = std::chrono::steady_clock::now();
	mat_mult_ijk(a, b, c);
	steady_clock::time_point end = std::chrono::steady_clock::now();
	
	/*
	for (int i = N/2; i < N/2 + 4; i++)
	{
		for(int j = N/2; j < N/2 + 4; j++)
		{
			cout << c[i * N + j] << " ";
		}
		cout << endl;
	}
	*/


	float time = duration_cast<microseconds>(end - begin).count();
	cout << "Total time = " << time << " microseconds" << endl;
	cout << "Time per 1 iteration = " << time / (N * N) * 1000 << " nanoseconds" << endl;


	delete [] a;
	delete [] b;
	delete [] c;
	return 0;
}