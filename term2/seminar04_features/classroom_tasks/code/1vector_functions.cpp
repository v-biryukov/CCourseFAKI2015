#include <iostream>
#include <vector>
#include <cstdlib>

using std::cout;
using std::endl;


// Векторы и другие контейнеры передаются в функции
// также, как и обычные переменные
// Конечно, лучше вектор передавать по ссылке
void print_vector(std::vector<int> vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

void print_vector_by_ref(const std::vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
}

// Вектор можно возвращать из функций
std::vector<int> generate_random_vector(int n, int max)
{
	std::vector<int> vec;
	for (int i = 0; i < n; ++i)
	{
		vec.push_back(rand() % max);
	}
	return vec;
}

int main()
{
	std::vector<int> v = generate_random_vector(30, 100);
	print_vector(v);
	print_vector_by_ref(v);

	// Задача 1:
	// Напишите функцию, sum_vector, которая будет принимать на вход вектор vector<int>
	// и возвращать его сумму
	// Напишите 2 варианта этой функции: с передачей вектора по значению и
	// с передачей вектора по ссылке


	// Задача 2:
	// Напишите функцию, которая принимает на вход вектор и возвращает
	// другой вектор, который будет содержать только чётные числа
	// Проверьте работу функции напечатав исходный вектор и возвращаемый вектор


	// Задача 3: 
	// Напишите функцию, которая будет принимать на вход вектор и
	// возводить каждый его элемент в квадрат. При этом эта функция
	// не должна ничего возвращать. Вектор должен измениться
	// Проверьте работу функции


}