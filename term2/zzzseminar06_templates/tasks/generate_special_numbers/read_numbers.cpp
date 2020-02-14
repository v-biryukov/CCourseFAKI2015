#include <iostream>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;

int main()
{
    // Создаём и открываем файл
    std::ifstream special_file;
    special_file.open ("special_numbers.txt");
    // Теперь с переменной special_file можно пользоваться также как и с cin
    int count;
    special_file >> count;

    // Создаём вектор и считываем в него числа
    std::vector<int> v;
    v.resize(count);
    for (int i = 0; i < count; i++)
        special_file >> v[i];

    // Печатаем первые 100 чисел
    for (int i = 0; i < 100; i++)
        cout << v[i] << " ";
}