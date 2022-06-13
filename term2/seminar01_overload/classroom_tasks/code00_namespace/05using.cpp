#include <stdio.h>

/*
    Если вам очень не хочется постоянно писать названия пространства имён,
    то вы можете использовать ключевое слово using

        using namespace audio;

    Это говорит о том, что начиная с этой строки audio:: перед именами писать больше не нужно

    Это, конечно, полностью уничтожают всю пользу, которую приносят пространства имён.
    То есть в больших проектах могут возникнуть ошибки, связанные с одинаковыми именами.

    Так что так лучше не делать, а если и делать, то только в маленьких программах.
*/


namespace audio 
{
    int a = 10;

    int calculate(int x)
    {
        return x + 1;
    }
}


namespace graphics 
{
    int a = 20;

    int calculate(int x)
    {
        return x * 2;
    }
}

namespace network 
{
    int b = 20;

    int solve(int x)
    {
        return x * 2;
    }
}

using namespace audio;

int main() 
{
    printf("%i\n", calculate(a));
}


/*
    Задание:

    1)  Что напечатает данная программа?

    2)  Если заменить  using namespace audio  на  using namespace graphics, то что напечатает программа?

    3)  Что если одновременно использовать пространство имён audio и пространство имён graphics?

            using namespace audio;
            using namespace graphics;

        Приведёт ли это к ошибке и, если да, то почему?


    4)  Что если одновременно использовать пространство имён audio и пространство имён network?

            using namespace audio;
            using namespace network;

        Приведёт ли это к ошибке и, если да, то почему?
*/