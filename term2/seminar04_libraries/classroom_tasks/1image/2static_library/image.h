// Класс пикселя
struct Color
{
    // Цвет пикселя кодируется 3-мя числами от 0 до 255
    unsigned char r, g, b;

    // 2 конструктора
    Color(){};
    Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};
};

// Класс координаты
struct Vector2i
{
    int x, y;

    Vector2i(int x0, int y0) : x(x0), y(y0){}

    Vector2i() : x(0), y(0){}

    Vector2i operator+(const Vector2i& right)
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
    int width, height;
    // Указатель на массив из пикселей
    // Память под этот массив нужно выделить в конструкторе
    Color* data;
public:
    // Конструктор по умолчанию, создает "пустую" картинку
    Image();
    // Конструктор, который создает экземпляр картинки, считывая её из файла
    Image(const char* filename);
    // Конструктор, который создаёт черную картинку размера width x height
    Image(int width, int height);

    // Конструктор, который создаёт черную картинку размера sizes.x x sizes.y
    Image(const Vector2i& sizes);

    // Деструктор, нужно не забыть освободить память
    ~Image();


    int get_width() const;
    int get_height() const;

    // Чтение/запись картинки из файла
    void read(const char* filename);
    void write(const char* filename) const;
    

    void clear(const Color& p = Color(0, 0, 0));
    // Метод, который обращает цвета картинки
    void reverse_colors();
    // Метод, который зеркально отображает картинку
    void flip_vertically();

    Color& at(int x, int y);
    void draw_circle(int radius, const Vector2i& center, const Color& p);

    void draw_line(float x1, float y1, float x2, float y2, const Color& color);
    void draw_line(const Vector2i& p1, const Vector2i& p2, const Color& color);

    // Установить цвет пикселя с координатами position
    void set_pixel(const Vector2i& position, const Color& p);
    // Вернуть пиксель с координатами position
    Color get_pixel(const Vector2i& position) const;
};
