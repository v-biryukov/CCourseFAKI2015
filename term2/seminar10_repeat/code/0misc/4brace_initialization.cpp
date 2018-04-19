#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>

using std::cout;
using std::endl;

struct Book
{
    std::string title;
    std::string author;
    int num_of_pages;
};

class Student
{
private:
    std::string name;
    int group;
    std::vector<int> grades;
public:
    Student(std::string init_name, int init_group) : name(init_name), group(init_group) {}
    Student(std::string init_name, int init_group, std::vector<int> init_grades) : 
            name(init_name), group(init_group), grades(init_grades) {}

    void print()
    {
        cout << name << " " << group << " grades: ";
        for (int g : grades)
            cout << g << " ";
    }
};


int main()
{
    // Начиная со стандарта C++11 можно всё инициализировать с помощью {}
    // Раньще это можно было делать только с массивами и структурами
    // Примеры:
    int a = 10;   // Обычная инициализация
    int b = {20}; // Brace initialization
    int c {30};   // Можно даже так
    // Проверка:
    cout << a << " " << b << " " << c << endl;


    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // Инициализируйте массив 5-ю произвольными значениями
    int arr[5] = <Ваш код>
    // Проверка:
    for (int x : arr)
        cout << x << " ";
    cout << endl;


    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // Инициализируйте вектор 5-ю произвольными значениями
    std::vector<int> vec = <Ваш код>
    // Проверка:
    for (int x : vec)
        cout << x << " ";
    cout << endl;


    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // Инициализируйте структуру Book
    Book book = {"abc", "vbn", 123};
    // Проверка:
    cout << "Book: " << book.title << " " << book.author << " " << book.num_of_pages << endl;


    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
    // Инициализируйте вектор векторов строк произвольными строками
    std::vector<std::vector<std::string>> vvs = <Ваш код>
    
    // Проверка:
    cout << "Testing vector of vectors of strings:\n";
    for (std::vector<std::string> x : vvs)
    {
        for (std::string s : x)
            cout << s << " ";
        cout << endl;
    }   

    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


    // Разные типы инициализации пользовательского класса:
    Student st1("Alice", 456);  // Вызывается 1-й конструктор
    Student st2("Bob", 789, {5, 4, 5, 3, 5});  // Вызывается 2-й конструктор
    Student st3 = Student("Cortney", 654, {5, 4, 5, 3, 5}); // то же самое
    
    // Инициализируйте класс Student, используя brace initialization (включая поле grades)
    Student st4 = <Ваш код>
    // Проверка:
    st4.print();

    // Инициализируйте вектор студентов, используя brace initialization (включая поле grades) и проверьте


}