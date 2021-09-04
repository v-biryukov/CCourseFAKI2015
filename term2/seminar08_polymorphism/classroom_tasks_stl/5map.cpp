#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;

// Вспомагательная функция для печати множества
void print_map(std::string header, const std::map<std::string, int>& m)
{
    cout << header << endl;
    for (auto el : m)
        cout << el.first << " " << el.second << endl;
    cout << endl;
}



int main()
{
    // Создаём словарь и вставляем элементы
    std::map<std::string, int> m;
    m["Moscow"] = 12000000;
    m["Paris"] = 50000000;
    m["Dolgoprudniy"] = 80000;
    m["Tokyo"] = 1300000;
    m["Milan"] = 14000000;


    print_map("Initial map:", m);
    /* Задание:

          1) Увеличьте население в городах в 2 раза

    */
}