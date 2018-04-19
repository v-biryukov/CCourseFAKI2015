#include <iostream>
#include <fstream>
#include <utility> // std::pair
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;

int main()
{

    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // |||||||||||||||| Дополнительные задачи на словарь |||||||||
    // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

    // Задача 1:

    // Создайте map<string, int> и подсчитайте сколько раз встречаются в тексте различные слова
    // Число элементов в map должно быть равно числу разлчных слов в тексте
    // Объявите map:

    // Считывание из файла по 1-му слову:
    std::ifstream file;
    file.open ("wp.txt");
    std::string word;
    while (!file.eof())
    {
        file >> word;
        // Что будет делать следующая строка?
        // cout << word << endl;
        // Ваш код здесь:


    }

    // Тестируем:
    // cout << "Pierre  --> " <<  m["Pierre"] << endl;
    // cout << "Bezuhov  --> " <<  m["Bezuhov"] << endl;
    // cout << "Rostov  --> " <<  m["Rostov"] << endl;
    // cout << "Rostova  --> " <<  m["Rostova"] << endl;
    // cout << "Natalya  --> " <<  m["Natalya"] << endl;
    // cout << "Bolkonsky  --> " <<  m["Bolkonsky"] << endl;
    // cout << "Kuragin  --> " <<  m["Kuragin"] << endl;
    // cout << "Napoleon  --> " <<  m["Napoleon"] << endl;
    // cout << "Kutuzov  --> " <<  m["Kutuzov"] << endl;
    // cout << "Moscow  --> " <<  m["Moscow"] << endl;
    // cout << "hope  --> " <<  m["hope"] << endl;

    



    // Задача 2:
    std::vector<std::string> names = {"Алисcа", "Борис", "Валерия", "Георгий", "Диана", "Егор", "Жанна", "Захар", 
                                      "Ирина", "Кирилл", "Любовь", "Максим", "Нина", "Олег", "Полина", "Роман", "Соня",
                                      "Тимофей", "Ульяна", "Филипп", "Юлия"};
    

    // Создайте map с первым элементом(ключом) типа std::string -- имя школьника и 
    // со вторым элементом типа std::vector<int> - вектор оценок школьника
    // Заполните этот словарь 21-м значением. Имена возьмите из вектора names
    // Длину вектора оценок задавайте случайным от 5 до 30
    // Сами оценки тоже задавайте случайным образом от 2 до 5
    // Ваш код:


    // Напечатайте ваш словарь используя range-based for loop в следующем формате
    // 
    // Имя       Оценки
    // Алисса    5 4 2 3 5 2 4
    // Борис     5 5 5 4 2 3 3 2 4 4 4 5
    // ...
    //
    // Ваш код:


    // Написать функцию 
    // void print_grades(const std::map<std::string, std::vector<int> >& m);
    // Которая будет печатать оценки


    // Посчитайте количество пятёрок у Полины
    // Ваш код:


    // Поставьте пятёрку Олегу
    // Ваш код:


    // Написать функцию 
    // void add_pupil(std::map<std::string, std::vector<int> >& m, std::string name, std::vector<int> grades);
    // Которая добавляет ученика с оценками в словарь m


    
    
}