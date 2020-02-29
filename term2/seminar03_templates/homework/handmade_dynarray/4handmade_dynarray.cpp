#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
struct Dynarray
{
	size_t size;
	size_t capacity;
	T* values;


	Dynarray(size_t initial_capacity)
	{
		if (initial_capacity < 0)
		{
			std::cout << "Dynarray's capacity has to be non-negative integer\n";
			exit(1);
		}
		size = 0;
		capacity = initial_capacity;
		values = new T[capacity];
	}

	Dynarray() : Dynarray(0)
	{
	}

	void push_back(T x)
	{
		if (size >= capacity)
		{
			if (capacity == 0)
				capacity = 1;
			else
				capacity *= 2;

			T* temp = new T[capacity];
			std::copy_n(values, size, temp);
			delete[] values;
			values = temp;
		}
		values[size] = x;
		size += 1;
	}

	void erase(size_t id)
	{
		if (id < 0 || id >= size)
		{
			std::cout << "Error while erasing element from Dynarray! Index is out of range\n";
			exit(1);
		}
		if (size == 0)
		{
			std::cout << "Error while erasing element from Dynarray! Dynarray is empty\n";
			exit(1);
		}
		for (size_t i = id; i < size - 1; i++)
			values[i] = values[i + 1];
		size--;
	}


	int is_empty()
	{
		return (size == 0);
	}

	~Dynarray()
	{
		delete[] values;
	}
};


using namespace std;

int main()
{
	Dynarray<int> a;
	for (int i = 1; i < 10; ++i)
	{
		a.push_back(i * i);
	}
	
	Dynarray<string> b;
	b.push_back("Echidna");
	b.push_back("Turtle");
	b.push_back("Coati");
	
	for (int i = 0; i < a.size; i++)
		cout << a.values[i] << "\n";

	for (int i = 0; i < b.size; i++)
		cout << b.values[i] << "\n";
}
