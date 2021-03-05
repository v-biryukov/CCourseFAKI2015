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
    int size_x, size_y;
    // Указатель на массив из пикселей
    // Память под этот массив нужно выделить в конструкторе
    Pixel* data;
public:
    // Конструктор по умолчанию, создает "пустую" картинку
    Image();
    // Конструктор, который создает экземпляр картинки, считывая её из файла .ppm
    Image(const char* filename);
    // Конструктор, который создаёт черную картинку размера size_x x size_y
    Image(int size_x, int size_y);

    // Деструктор
    ~Image();


    int get_size_x();
    int get_size_y();

    // Чтение/запись картинки из файла
    void read(const char* filename);
    void write(const char* filename);
    
    // Функция, которая обращает цвета картинки
    void reverse_colors();
    // Функция, которая зеркально отображает картинку
    void flip_vertically(); 

    // Установить цвет пикселя с координатами (x, y)
    void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b);
    void set_pixel(int x, int y, const Pixel& p);
    // Вернуть пиксель с координатами (x, y)
    Pixel get_pixel(int x, int y);
};
