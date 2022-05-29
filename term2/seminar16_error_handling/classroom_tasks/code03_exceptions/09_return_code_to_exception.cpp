#include <iostream>
#include <fstream>

/*
    Измените данную программу так, чтобы для обработки ошибок тут использовались
    исключения, а не коды возврата.
*/


// Загружает данные о текстуре и возвращает true если всё прошло успешно
bool loadTextureData(const std::string& filePath)
{
    // ...
    std::ifstream file(filePath);
    if (file.fail())
    {
        return false;
    }
    // ...
    return true;
}

// Вызывает loadTextureData для считывания данных о текстуре
// Затем обрабатывает эти данные и представляет текстуру в нужном нам формате
bool generateTexture(const std::string& filePath)
{
    // ...
    bool result = loadTextureData(filePath);
    if (!result)
    {
        return false;
    }
    // ...
    return true;
}



int main()
{
    bool result = generateTexture("texture.bmp");
    if (!result)
    {
        bool result = generateTexture("default.bmp");
        if (!result)
        {
            std::cout << "Error! Can't find any texture files.\n";
        }
    }
}


