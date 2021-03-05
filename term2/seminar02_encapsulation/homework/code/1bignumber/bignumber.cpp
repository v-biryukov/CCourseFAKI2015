#include <iostream>
#include <algorithm>

struct Number
{
	static const int bucket_size = 100;
	int size;
	unsigned char* data;


	Number(int a)
	{
		int b = a;
		size = 0;
		while (b != 0)
		{
			b /= bucket_size;
			size += 1;
		}
		data = new unsigned char[size];
		for (int i = 0; i < size; ++i)
		{
			data[i] = a % bucket_size;
			a /= bucket_size;
		}
	}

	Number operator+(const Number& right) const
	{
		Number result{ 0 };
		result.size = std::max(size, right.size);
		if (size == right.size && data[size - 1] + right.data[size - 1] >= bucket_size)
		{
			result.size += 1;
			result.data[result.size - 1] = 1;
		}

		result.data = new unsigned char[result.size];
		int residue = 0;
		for (int i = 0; i < std::max(size, right.size); ++i)
		{
			int sum = data[i] + right.data[i];
			result.data[i] = sum % bucket_size + residue;
			residue = sum / bucket_size;
		}
		return result;
	}

	void print_info()
	{
		std::cout << "Size = " << size << std::endl;
		for (int i = 0; i < size; ++i)
		{
			std::cout << data[i] << std::endl;
		}
	}
};

std::ostream& operator<<(std::ostream& stream, const Number& right)
{
	for (int i = right.size - 1; i >= 0; --i)
	{
		stream << (int)right.data[i];
	}
	return stream;
}


int main()
{
	Number a {90};
	Number b {17};
	//Number c = a + b;
	std::cout << a + b;
}