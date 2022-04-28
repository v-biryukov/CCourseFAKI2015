#include <iostream>
using namespace std;

template <typename T>
T getMax(T a, T b) {
    return a > b ? a : b;
}



int main() {
    float x = 5.5;
    float y = 1.7;
    cout << getMax(x, y) << endl;
    cout << getMax(4, 7) << endl;

    // Компилятор сам понял, какую функцию нужно сгенерировать по типам аргументов
    
    // Однако, можно задать какую именно функцию можно вызывать 
    cout << getMax<int>(x, y) << endl;
}