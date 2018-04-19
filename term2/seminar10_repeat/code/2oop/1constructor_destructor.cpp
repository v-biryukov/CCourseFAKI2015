#include <stdlib.h>  // malloc/free
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
    
public:

    Student()
    {
        name = "Vasya";
        group = 0;
        cout << "Default constructor. Name = " << name  << endl;
    }
    Student(std::string init_name, int init_group) : name(init_name), group(init_group) 
    {
        cout << "Constructor. Name = " << name << endl;
    }
    ~Student()
    {
        cout << "Destructor. Name = " << name << endl;
    }
};


int main()
{
    Student a;
    Student b("Alisa", 777);

    Student* p = new Student("Bob", 666);

    Student* q = (Student*)malloc(sizeof(Student));

    delete p;
    free(q);

    // Что напечатает эта программа?
    // В чем разница между malloc и new
}