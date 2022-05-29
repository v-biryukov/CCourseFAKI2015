#include <iostream>
using std::cout, std::endl;


struct Time 
{
    int minutes;
    int seconds;
};

Time operator+(Time t, int x)
{
    Time result = t;
    result.seconds += x;
    
    result.minutes += (result.seconds / 60);
    result.seconds %= 60;

    return result;
}

Time operator+(int x, Time t)
{
    return t + x;
}

Time operator+(Time ta, Time tb)
{
    Time result = ta;
    result.seconds += 60 * tb.minutes + tb.seconds;
    
    result.minutes += (result.seconds / 60);
    result.seconds %= 60;

    return result;
}


int main() 
{
    Time a = {20, 10};
    Time b = a + 90;
    Time c = 90 + a;
    Time d = a + b;

    cout << b.minutes << " " << b.seconds << endl;
    cout << c.minutes << " " << c.seconds << endl;
    cout << d.minutes << " " << d.seconds << endl;

}
