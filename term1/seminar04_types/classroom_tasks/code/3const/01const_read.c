/*
    Константы

    Слово const означает, что вы не сможете поменять эту переменную после её инициализации.
    Но инициализировать константу при её создании можно чем угодно.
    В том числе и значением, считанным с помощью scanf.
*/


int main()
{
    int n;
    scanf("%i", &n);

    const int a = n;

    printf("%i\n", a);
}