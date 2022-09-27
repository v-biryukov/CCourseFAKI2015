#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char* read_from_file_fgetc(const char* filename)
{
    FILE* fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    printf("In function c: %zu\n", file_size);

    char* str = (char*)malloc(file_size + 1);

    for (size_t i = 0; i < file_size; ++i)
    {
        str[i] = (char)fgetc(fp);
    }
    str[file_size] = '\0';

    fclose(fp);
    return str;
}


char* read_from_file_fgets(const char* filename)
{
    FILE* fp = fopen(filename, "r");
    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* str = (char*)malloc(file_size + 1);
    str[0] = '\0';

    char temp[500];
    while(fgets(temp, 500, fp)) 
    {
        strcat(str, temp); // N^2
    }

    str[file_size] = '\0';

    fclose(fp);
    return str;
}




char* read_from_file_fread(const char* filename)
{
    FILE* fp = fopen(filename, "r");

    fseek(fp, 0, SEEK_END);
    size_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* str = (char*)malloc(file_size + 1);
    fread(str, file_size, 1, fp);
    str[file_size] = '\0';

    fclose(fp);
    return str;
}


size_t calculate_char_sum(const char* str)
{
    size_t result = 0;

    for (size_t i = 0; str[i]; ++i)
    {
        result += str[i];
    }

    return result;
}



int main()
{
    char* content = read_from_file_fread("books/war_and_peace.txt");

    //printf("%s\n", content);

    printf("%zu\n", calculate_char_sum(content));
   
}