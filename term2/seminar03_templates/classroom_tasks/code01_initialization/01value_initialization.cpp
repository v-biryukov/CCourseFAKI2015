#include <iostream>
#include <string>
using std::cout, std::endl;


/* Инициализация по значению
   T a {};


*/



// Простой класс с перегруженным дружественным оператором  ostream << Point
class Point 
{
    int x, y;

public:

    friend std::ostream& operator<<(std::ostream& left, const Point& right);
};

std::ostream& operator<<(std::ostream& left, const Point& right) {
    left << "(" << right.x << ", " << right.y << ")";
    return left;
}





int main() 
{
    // Переменные основных типов инициализируются нулём в этом случае
    int x {};
    cout << x << endl;

    // Массивы по умолчанию ализируются нулём в этом случае
    int arr[10] {};
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Для классов вызывается конструктор по умолчанию, также как и в случае инициализации по умолчанию
    // В этом примере создастся пустая строка ""
    std::string s {};
    cout << s << endl;

    // Если у класса нет конструктора по умолчанию, то компилятор сам сгенерирует его: Point() {}
    Point p {};
    cout << p << endl;
}