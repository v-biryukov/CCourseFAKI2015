#include <iostream>
#include <string>

template <typename T>
class SmartPointer
{
private:
    T* pointer;

public:
    SmartPointer(T* pointer) : pointer(pointer) {}
    T& operator*()  const {return *pointer;}
    T* operator->() const {return pointer;}

    ~SmartPointer() 
    {
        std::cout << "Deleting" << std::endl;
        delete pointer;
    }
};

int main()
{
    SmartPointer<int> q = new int(10);
} 