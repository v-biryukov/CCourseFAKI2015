/*
    Копирование и перемещение

    
    Копирование

        Под копированием в языке C++ обычно понимается глубокое копирование.


    Перемещение

        Под перемещением в языке C++ понимается операция, состоящая из двух частей:

        1)  Поверхностное копирование
        2)  Изменение объекта, из которого производится перемещение. Объект должен перестать владеть ресурсом, 
            но должен находится в корректном состоянии. Каким будет это корректное состояние может различаться для разных типов.

        Перемещение объекта осуществляется с помощью специальной функции std::move.
        Функция std::move находится в библиотеке utility, но эта библиотека подключается к другим
        стандартным библиотекам, так что часто std::move будет работать даже если вы не подключите эту библиотеку.
*/


int main() {}
