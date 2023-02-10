#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>

namespace mipt {

using ComponentType = std::uint8_t;

// Класс цвета
struct Color
{
    // Цвет пикселя кодируется 3-мя числами, как правило от 0 до 255
    ComponentType r, g, b;


    Color() : r(0), g(0), b(0) {};
    Color(ComponentType r, ComponentType g, ComponentType b) : r(r), g(g), b(b) {};
    Color(int r, int g, int b) : r(r), g(g), b(b) {};
};

// Класс координаты
struct Vector2i
{
    int x, y;

    Vector2i(int x0, int y0) : x(x0), y(y0){}
    Vector2i() : x(0), y(0){}

    Vector2i operator+(Vector2i right)
    {
        Vector2i temp = {x + right.x, y + right.y};
        return temp;
    }
};


// Класс картинки
class Image
{
private:
    // Размеры изображения
    int mWidth {};
    int mHeight {};
    

    // Компоненты цветов храним в одном векторе
    // Этот вектор будет хранить mWidth * mHeight * 3 элементов
    std::vector<ComponentType> mData {};

    
public:

    // Конструктор по умолчанию, создает "пустую" картинку
    Image();

    // Конструктор, который создает экземпляр картинки, считывая её из файла
    Image(const std::string& filename);

    // Конструктор, который создаёт черную картинку размера width x height
    Image(int width, int height);

    // Конструктор, который создаёт черную картинку размера sizes.x x sizes.y
    Image(Vector2i sizes);

    // Получить ширину, высоту, количество пикселей (ширина * высота) и количество компонент (ширина * высота * 3)
    int getWidth() const;
    int getHeight() const;
    int getNumberOfPixels() const;
    int getNumberOfComponents() const;

    // Получить ссылку на channel компоненту цвета пикселя с координатами x и y
    // channel может принимать значения 0 (red), 1 (green) или 2 (blue)
    ComponentType& at(int x, int y, int channel);

    // Установить цвет пикселя с координатами position
    void setPixel(Vector2i position, Color p);
    // Вернуть пиксель с координатами position
    Color getPixel(Vector2i position) const;

    // Чтение/запись картинки из файла в формате .ppm (ppm-файл не должен содержать # комментарии)
    void read(const std::string& filename);
    void write(const std::string& filename) const;
    
    // Закрасить картинку цветом c
    void clear(Color c = Color{0, 0, 0});

    // Метод, который обращает цвета картинки
    void reverseColors();

    // Метод, который зеркально отображает картинку
    void flipVertically();


    // Нарисовать на изображении круг или линию
    void drawCircle(int radius, Vector2i center, Color p);
    void drawLine(Vector2i p1, Vector2i p2, Color color);
};

}