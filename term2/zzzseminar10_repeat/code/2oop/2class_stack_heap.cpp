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

    // Напишите конструктор вида:
    // Student(std::string name, int group)


    // Напишите функцию void give_grade(int grade)
    // которая добавляет оценку в вектор grades

    void print_grades()
    {
        // Печатаем оценки из вектора grades
        for (std::vector<int>::iterator it = grades.begin(); it != grades.end()-1; ++it)
            cout << *it << ", ";
        cout << *(grades.end()-1) << endl;
    }

    ~Student()
    {
        cout << "Destructor: name = " << name << endl;
    }
};


int main()
{

    //Student a("Alisa", 777); // Создаём студента a на стеке
    a.give_grade(5);
    a.give_grade(4);
    a.give_grade(3);
    a.give_grade(3);
    a.give_grade(3);
    a.give_grade(4);
    a.give_grade(5);
    a.print_grades();


    // Создайте студента b по имени Bob и с номером группы 666
    // Только в этом случае создайте его в куче и используйте операторы new и delete
    // Проставьте ему несколько оценок и напечатайте их


}