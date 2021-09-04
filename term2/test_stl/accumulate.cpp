#include <iostream>
#include <cmath>
#include <numeric>
#include <chrono>

using namespace std::chrono;
using std::cout;
using std::endl;

#define N 100'000'000 


int* create_random_array(int M)
{
	int* array = new int[N];
	for (int i = 0; i < N; ++i)
	{
		array[i] = rand() % M;
	}
	return array;
}



int main()
{
	int sum = 0;
	int* a = create_random_array(1000);


	steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (int i = 0; i < N; ++i)
	{
		sum += *(a+i);
	}
	steady_clock::time_point end = std::chrono::steady_clock::now();

	float time = duration_cast<nanoseconds>(end - begin).count();
	cout << "Simple: Result = " << sum << endl;
	cout << "Simple: Total time = " << time << " nanoseconds" << endl;
	cout << "Simple: Time per 1 iteration = " << time / N << " nanoseconds" << endl;



	begin = std::chrono::steady_clock::now();
	sum = std::accumulate(a, a + N, 0);
	end = std::chrono::steady_clock::now();

	time = duration_cast<nanoseconds>(end - begin).count();
	cout << "Accumulate: Result = " << sum << endl;
	cout << "Accumulate: Total time = " << time << " nanoseconds" << endl;
	cout << "Accumulate: Time per 1 iteration = " << time / N << " nanoseconds" << endl;


	delete [] a;
	return 0;
}