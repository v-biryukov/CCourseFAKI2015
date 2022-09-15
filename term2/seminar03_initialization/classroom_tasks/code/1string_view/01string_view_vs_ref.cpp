/*
    Сравнение передачи по string_view и передачи по const string&
    Обычно string_view используется для передачи строки в функцию, в которой она не будет меняться.
    При этом string_view передаётся по значению.

        class string_view
        {
        private:
            const char* mpData;
            size_t size;

        public:

            // ...
        }

    
    Почему передача по string_view быстрее, чем передача по const string&  ?
        
        1)  При передаче по string_view мы копируем в функцию сразу указатель на данные
            
            Тогда как при передаче по константной ссылке мы копируем указатель (ссылка это синтаксический сахар для указатель) 
            на объект string. И уже этот объект содержит указатель на данные (а также он содержит size и capacity).
            Чтобы получить доступ непосредственно к данным нужно дважды пройти по указателю


        2)  Если мы в функцию, принимающую по костантной ссылке, передаём строковой литерал:
                countDigits1("cat123dog")
            то если мы принимаем , то мы должны создать объект std::string из const char*
            Вызовется конструктор, возможно будет динамическое выделение памяти (если строка не короткая), это долго.
        

            Если же мы в функцию, принимающую по string_view, передаём строковой литерал:
                countDigits2("cat123dog")
            то в этом случае в string_view просто зададутся указатель и размер, так чтобы указатель указывал на строку-литерел.
            Это гораздо быстрее.
*/

#include <iostream>
#include <ctype.h>
#include <string>
#include <string_view>

using std::cout, std::cin, std::endl;


int countDigits1(const std::string& str)
{
    int result = 0;
    for (int i = 0; i < str.size(); ++i)
        if (std::isdigit(str[i]))
            result++;
    return result;
}

int countDigits2(std::string_view str)
{
    int result = 0;
    for (int i = 0; i < str.size(); ++i)
        if (std::isdigit(str[i]))
            result++;
    return result;
}



int main()
{
    std::string a = "Ab5c5jjaWi$ 102 a 4 abc2";

    cout << countDigits1(a) << endl;
    cout << countDigits2(a) << endl;


    cout << countDigits1("cat123dog") << endl;
    cout << countDigits2("cat123dog") << endl;
}