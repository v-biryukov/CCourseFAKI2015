#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <vector>
#include <algorithm>



int main()
{
	const int number_of_elements = 2e4;
    const int max = 1e5;

    // Инициализируем генератор случайных чисел
    srand(time(0));
    std::rand();


    // Генерируем уникальное число
    int unique = std::rand() % max;
    // std::cout << unique << std::endl;

    // Генерируем вектор нужного размера из остальных чисел
    std::vector<int> v;
    v.reserve(number_of_elements);
    v.push_back(unique);
    while (v.size() < number_of_elements)
    {
        int new_number = rand() % max;
        if (new_number != unique)
        {
	        v.push_back(new_number);
	        v.push_back(new_number);
	    }
    }
    // Перемешиваем этот вектор
    std::random_shuffle(v.begin(), v.end());

    // Записываем содержимое вектора в файл special_numbers.txt
    std::ofstream special_file;
    special_file.open ("special_numbers.txt");
    special_file << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        special_file << v[i] << " ";
    special_file.close()
}