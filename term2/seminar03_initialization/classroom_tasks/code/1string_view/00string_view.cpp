/*
    Класс std::string_view

    Идёт в дополнение к классу std::string и позволяет ускорить программу.
    std::string_view это очень маленький класс, который состоит из двух полей:

        class string_view
        {
        private:
            const char* mpData;
            size_t size;

        public:

            // ...
        }

    В отличии от класса std::string этот класс не "владеет" самими данными (массивом char).
    При копировании string_view копируется только сам объект (указатель mpData и размер size)
    А данные, на которые указывает mpData, не копируются вместе с самим объектом.
    В каком-то смысле string_view ведёт себя похоже на указатель.


    string_view во многих случаях позволяет писать более эффектиный код, но при этом его использование
    может привести к ошибкам, аналогичным ошибкам при работе с указателями.
    Особенно часто string_view используется при передаче строк в функции.
*/




#include <iostream>
#include <string>
#include <string_view>

using std::cout, std::cin, std::endl;


int main()
{
    std::string a = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed imperdiet dolor eu velit gravida iaculis.";

    std::string_view b = a;
    cout << b << endl;
}


/*
    Задача:
        
        Как вы думаете как передавать в функцию строку более эффективно: по константной ссылке или по string_view?
        И почему один из этих методов более эффективен?

*/