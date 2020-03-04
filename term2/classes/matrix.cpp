#include <iostream>


template <typename T>
class Matrix
{
private:
	size_t width;
	size_t height;
	T* data;
public:
	Matrix(size_t w, size_t h) : width(w), height(h)
	{
		data = new T[width * height];
	}

	Matrix(const Matrix& m) : width(m.width), height(m.height)
	{
		data = new T[width * height];
		std::copy_n(m.data, width * height, data);
	}

	Matrix& operator=(const Matrix& m)
	{
		if (&m == this)
			return *this;

		delete data;
		width = m.width;
		height = m.height;
		data = new T[width * height];
		std::copy_n(m.data, width * height, data);
	}

	~Matrix()
	{
		delete data;
	}

	Matrix& operator


};