#include <stdio.h>

/*
    Если вам очень не хочется постоянно писать названия пространства имён,
    то вы можете использовать ключевое слово using

        using namespace mipt;

    Это говорит о том, что начиная с этой строки mipt:: перед именами писать больше не нужно

    Это, конечно, полностью уничтожают всю пользу, которую приносят пространства имён.
    То есть в больших проектах могут возникнуть ошибки, связанные с одинаковыми именами.

    Так что так лучше не делать, а если и делать, то только в маленьких программах.
*/


namespace mipt 
{
    int a = 5;
    float b = 1.2;

    int square(int x)
    {
        return x * x;
    }
}

using namespace mipt;


int main() 
{
    printf("%i\n", square(a));
}


/*
    Задание:

    1)  Что напечатает данная программа?

    2) 
*/