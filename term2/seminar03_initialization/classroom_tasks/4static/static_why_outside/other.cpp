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

int Rectangle::value = 20;      


void func()
{
    std::cout << Rectangle::value << std::endl;
}              
