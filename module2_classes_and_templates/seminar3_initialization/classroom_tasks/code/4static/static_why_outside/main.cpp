/*
    Для компиляции:

        g++ main.cpp other.cpp

*/


#include <iostream>             
                                
class Rectangle                 
{                               
private:                        
    float mWidth;               
    float mHeight;              
                                
public:                         
    Rectangle(float, float);    
    static int value;      
};                        

//int Rectangle::value = 10;      

void func();                      
                                
int main()                      
{                               
    std::cout << Rectangle::value << std::endl;

    func();
}                               
                                