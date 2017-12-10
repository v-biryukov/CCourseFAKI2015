#include <stdio.h>
#include <string.h>

// Компилируйте с опцией std=c99
// Так:  gcc -std=c99 ./string_tasks.c


void uppercase(char* str)
{
    for (int i = 0; str[i]; ++i)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
}

int main()
{
    printf("\nProblem 1: ASCII\n");
    for (int i = 0; i < 128; ++i)
        printf("%c", i);
    printf("\n");


    printf("\nProblem 2: Modify\n");
    char str1[50] = "a bunch of characters";
    str1[2] = 'B';
    str1[11] = 'C';
    printf("%s\n", str1);


    printf("\nProblem 3: Shortening a string\n");
    char str2[50] = "some,words,here";
    int str2_length = strlen(str2);
    for (int i = 0; i < str2_length; ++i)
        if (str2[i] == ',')
        {
            str2[i] = '\0';
            break;
        }
    printf("%s\n", str2);

    
    printf("\nProblem 4: for_6\n");
    printf("Enter 1 digit and 1 long number\n");
    char digit;
    char long_number[1002];
    scanf("%c%s", &digit, long_number);
    int count = 0;
    int long_number_length = strlen(str2);
    for (int i = 0; i < long_number_length; ++i)
        if (long_number[i] == digit)
            count++;
    printf("Digit %c encountered %d times\n", digit, count);


    printf("\nProblem 5: Inverse\n");
    printf("Enter a string without spaces: ");
    char str3[100];
    scanf("%s", str3);
    int length = strlen(str3);
    printf("String before reversing: %s\n", str3);
    for (int i = 0; i < length / 2; ++i)
    {
        char temp = str3[i];
        str3[i] = str3[length - 1 - i];
        str3[length - 1 - i] = temp;
    }
    printf("String after reversing: %s\n", str3);


    printf("\nProblem 6: Substring\n");
    char str[1000];
    char substr[100];
    printf("Enter a string and a substring\n");
    scanf("%s%s", str, substr);
    if (strstr(str, substr) == NULL)
        printf("NO\n");
    else
        printf("YES\n");


    printf("\nProblem 7: Uppercase\n");
    char str4[100];
    scanf("%s", str4);
    printf("Before uppercase(): %s\n", str4);
    uppercase(str4);
    printf("After uppercase(): %s\n", str4);

    return 0;
}
