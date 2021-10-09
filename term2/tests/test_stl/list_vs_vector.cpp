#include <iostream>
#include <cmath>
#include <numeric>
#include <chrono>
#include <vector>
#include <list>
#include <set>

using namespace std::chrono;
using std::cout;
using std::endl;

#define N 1'000'000 


std::vector<int> create_random_vector(int n, int m)
{
	std::vector<int> result(n);
	for (int i = 0; i < N; ++i)
	{
		result.push_back(rand() % m);
	}
	return result;
}

std::list<int> create_random_list(int n, int m)
{
	std::list<int> result;
	for (int i = 0; i < N; ++i)
	{
		result.push_back(rand() % m);
	}
	return result;
}

std::multiset<int> create_random_set(int n, int m)
{
	std::multiset<int> result;
	for (int i = 0; i < N; ++i)
	{
		result.insert(rand() % m);
	}
	return result;
}


int main()
{
	int sum = 0;

	std::vector<int> v = create_random_vector(N, 1000);
	steady_clock::time_point begin = std::chrono::steady_clock::now();

	sum = std::accumulate(v.begin(), v.end(), 0);

	steady_clock::time_point end = std::chrono::steady_clock::now();

	float time = duration_cast<nanoseconds>(end - begin).count();

	cout << "Vector: Sum = " << sum << endl; 
	cout << "Vector: Total time = " << time << " nanoseconds" << endl;
	cout << "Vector: Time per 1 iteration = " << time / N << " nanoseconds" << endl;


	cout << endl;
	std::list<int> l = create_random_list(N, 1000);
	begin = std::chrono::steady_clock::now();
	sum = std::accumulate(l.begin(), l.end(), 0);
	end = std::chrono::steady_clock::now();

	time = duration_cast<nanoseconds>(end - begin).count();
	cout << "List: Sum = " << sum << endl; 
	cout << "List: Total time = " << time << " nanoseconds" << endl;
	cout << "List: Time per 1 iteration = " << time / N << " nanoseconds" << endl;



	cout << endl;
	std::multiset<int> s = create_random_set(N, 1000);
	begin = std::chrono::steady_clock::now();
	sum = std::accumulate(s.begin(), s.end(), 0);
	end = std::chrono::steady_clock::now();

	time = duration_cast<nanoseconds>(end - begin).count();
	cout << "Multiset: Sum = " << sum << endl; 
	cout << "Multiset: Total time = " << time << " nanoseconds" << endl;
	cout << "Multiset: Time per 1 iteration = " << time / N << " nanoseconds" << endl;


	return 0;
}