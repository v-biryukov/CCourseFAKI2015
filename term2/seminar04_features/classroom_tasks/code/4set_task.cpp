#include <iostream>
#include <set>
#include <vector>
#include <chrono> // Библиотека для измерения времени

using std::cout;
using std::endl;

void print_set(const std::set<int>& s)
{
	for (int el : s)
		cout << el << " ";
	cout << endl;
}

void print_vector(const std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

std::set<int> generate_random_set(int n, int max)
{
	std::set<int> s;
	while (s.size() != n)
	{
		s.insert((rand() * RAND_MAX + rand()) % max);
	}
	return s;
}

std::vector<int> generate_random_vector(int n, int max)
{
	std::vector<int> vec;
	for (int i = 0; i < n; ++i)
	{
		vec.push_back((rand() * RAND_MAX + rand()) % max);
	}
	return vec;
}



int main()
{
	std::vector<int> numbers = generate_random_vector(70, 100);
	int a = 100;

	std::vector<int> v;
	for (int i = 0; i < numbers.size(); ++i)
	{
		for 
	}


	using namespace std::chrono;
	int ms1 = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}