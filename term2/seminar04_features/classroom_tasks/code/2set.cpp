#include <iostream>
#include <set>
#include <chrono> // Библиотека для измерения времени

using std::cout;
using std::endl;

// set можно передавать в функции также как и обычные переменный
void print_set(const std::set<int>& s)
{
	for (int el : s)
		cout << el << " ";
	cout << endl;
}

// set можно возвращать из функций также как и обычные переменный
std::set<int> generate_random_set(int n, int max)
{
	std::set<int> s;
	while (s.size() != n)
	{
		s.insert((rand() * RAND_MAX + rand()) % max);
	}
	return s;
}


int main()
{
	std::set<int> s = {15, 12, 20, 6, -1, 4};
	// set(множество) это контейнер, у которого нет доступа по индексу
	// Но зато остальные операции работают намного быстрее
	// Под капотом set представляет собой бинарное дерево поиска

	// 1) Добавление элемента в set:
	s.insert(17);

	// 2) Итерации по множеству
	// Обычный способ не сработает, так как у set нет operator[]
	// Но сработаю итераторы
	// При этом, нужно понимать, что, например, ++it - это сложная 
	// перегруженная операция перехода к следующему элементу дерева
	for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
		cout << *it << " ";
	cout << endl;

	// range-based цикл тоже работает
	for (int el : s)
		cout << el << " ";
	cout << endl;


	s = generate_random_set(30, 100); 
	print_set(s);

	// Задача:
	// Напишите функцию, которая принимает на вход set и возвращает сумму всех элементов

	using namespace std::chrono;
	int ms1 = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}