#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;


class Student
{
private:
    std::string name;
    int group;
    std::vector<int> grades;

public:

    Student()
    {
        cout << "Default constructor" << endl;
    }

    Student(std::string name, int group, std::vector<int> grades) 
            : name(name), group(group), grades(grades) {}


    void give_grade(int grade)
    {
        grades.push_back(grade);
    }

    // const может стоять много где
    // const int do_something(const float* p) const
    // Первый const: возвращаемое значение -- константа
    // Второй const: то, на что указывает p -- константа
    // Третий const (после метода): этот метод не изменяет поля класса

    // print_grades() не изменяет поля класса
    void print_grades() const
    {
        for (int g : grades)
            cout << g << " ";
        cout << endl;
    }


    // В чём различие между этими методами
    std::vector<int> get_grades1() const
    {
        return grades;
    }

    std::vector<int>& get_grades2()
    {
        return grades;
    }

    const std::vector<int>& get_grades3() const
    {
        return grades;
    }
};


int main()
{
    Student s = {"Alice", 777, {3, 3, 4, 4, 5, 5, 5, 5}};
    s.print_grades();

    s.get_grades1()[0] += 1;
    s.get_grades1().push_back(2);
    s.print_grades();

    s.get_grades2()[0] += 1;
    s.get_grades2().push_back(2);
    s.print_grades();

    //s.get_grades3()[0] += 1;
    //s.get_grades3().push_back(2);
    //s.print_grades();


    // Поставьте const у метода get_grades2() и скомпилируйте программу
}