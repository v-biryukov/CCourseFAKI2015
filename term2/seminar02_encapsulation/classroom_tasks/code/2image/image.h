#include <stdio.h>
#include <stdlib.h>

// Класс пикселя
struct Pixel 
{
    // Цвет пикселя кодируется 3-мя числами от 0 до 255
    unsigned char r, g, b;

    // 2 конструктора
    Pixel(){};
    Pixel(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};

    // оператор присваивания
    Pixel& operator=(const Pixel& c) 
    {
        r = c.r;
        g = c.g;
        b = c.b;
        return *this;
    }

};

// Класс картинки
class Image 
{
private:
    // Размеры изображения
    int sizeX, sizeY;
    // Указатель на массив из пикселей
    // Память под этот массив нужно выделить в конструкторе
    Pixel* data;
public:
    // Конструктор по умолчанию, создает "пустую" картинку
    Image();
    // Конструктор, который создает экземпляр картинки, считывая её из файла .ppm
    Image(const char* filename);
    // Конструктор, который создаёт черную картинку размера sizeX x sizeY
    Image(int sizeX, int sizeY);

    // Деструктор
    ~Image();


    int getSizeX();
    int getSizeY();

    // Чтение/запись картинки из файла
    void read(const char* filename);
    void write(const char* filename);
    
    // Функция, которая обращает цвета картинки
    void reverseColors();
    // Функция, которая зеркально отображает картинку
    void flipVertically(); 

    // Установить цвет пикселя с координатами (x, y)
    void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
    void setPixel(int x, int y, const Pixel& p);
    // Вернуть пиксель с координатами (x, y)
    Pixel getPixel(int x, int y);
};
