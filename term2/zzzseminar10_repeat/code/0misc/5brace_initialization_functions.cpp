#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
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


void print_vector(const std::vector<int>& v)
{
    for (int el : v)
        cout << el << " ";
    cout << endl;
}

void print_students(const std::vector<Student>& students)
{
    for (Student s : students)
    {
        s.print();
        cout << endl;
    }
    
}


int main()
{
    cout << "Numbers:" << endl;
    // Создаём вектор, а затем его печатаем:
    std::vector<int> vec = {1, 5, 10, 20, 5};
    print_vector(vec);

    // Так делать нельзя, {} только при инициализации
    // vec = {5, 3, 2, 10, 12};

    // Но так делать можно: Создаётся временный вектор, инициализируется и передаётся в функцию
    print_vector({5, 4, 3, 9, 8});


    cout << "\nStudent:" << endl;
    // Инициализируйте вектор студентов
    std::vector<Student> students = {{"Alisa",   456, {5, 5, 4, 5, 4}}, 
                                     {"Bob",     789, {3, 2, 2, 2, 4, 5, 4, 5}}, 
                                     {"Cortney", 987, {5}}
                                    };
    print_students(students);

    // Передайте в функцию print_students временный вектор
    // Ваш код:


}