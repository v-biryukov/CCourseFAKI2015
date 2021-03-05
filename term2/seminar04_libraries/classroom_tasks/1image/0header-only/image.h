#include <iostream>
#include <functional>
#include <cmath>

// Класс пикселя
struct Color
{
    // Цвет пикселя кодируется 3-мя числами от 0 до 255
    unsigned char r, g, b;

    // 2 конструктора
    Color(){};
    Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};
};

// Класс 2D вектора, чьи координаты имеют тип int
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
    Image()
    {
        data = nullptr;
    }
    // Конструктор, который создает экземпляр картинки, считывая её из файла
    Image(const char* filename)
    {
        data = nullptr;
        read(filename);
    }
    // Конструктор, который создаёт черную картинку размера width x height
    Image(int w, int h) : width(w), height(h)
    {
        data = new Color[width * height];
    }

    // Конструктор, который создаёт черную картинку размера sizes.x x sizes.y
    Image(const Vector2i& sizes) : width(sizes.x), height(sizes.y)
    {
        data = new Color[width * height];
    }

    // Деструктор, нужно не забыть освободить память
    ~Image()
    {
        delete data;
    }


    int get_width() const
    {
        return width;
    }

    int get_height() const
    {
        return height;
    }

    // Чтение/запись картинки из файла
    void read(const char* filename)
    {
        FILE* inputfile = fopen(filename, "rb");
        if (inputfile == nullptr)
        {
            std::cout << "Can't open the file: " << filename << std::endl;
            std::exit(1);
        }
        fscanf(inputfile, "P6\n%d %d\n255\n", &width, &height);
        data = (Color*)malloc(sizeof(Color) * width * height);
        fread(data, sizeof(Color), width * height, inputfile);
        fclose(inputfile);
    }

    void write(const char* filename) const
    {
        FILE* outputfile = fopen(filename, "wb");
        fprintf(outputfile, "P6\n%d %d\n255\n", width, height);
        fwrite(data, sizeof(Color), height * width, outputfile);
        fclose(outputfile);
    }
    

    void clear(const Color& p)
    {
        for (int j = 0; j < height; j++)
            for (int i = 0; i < width; i++)
                data[i + j*width] = p;
    }
    // Метод, который обращает цвета картинки
    void reverse_colors()
    {
        if(data)
        {
             for(int i = 0; i< width * height; i++)
             {
                  data[i].r = 255 - data[i].r;
                  data[i].g = 255 - data[i].g;
                  data[i].b = 255 - data[i].b;
             }
        }
    }  

    // Метод, который зеркально отображает картинку
    void flip_vertically()
    {
        Color temp;
        if(data)
        {
            for(int j = 0; j < height / 2; j++)
            {
                for(int i = 0; i < width; i++)
                {
                    temp = data[i + j * width];
                    data[i + j*width] = data[i + (height - j - 1) * width];
                    data[i + (height - j - 1) * width] = temp;
                }
            }
        }
    }


    Color& at(int x, int y)
    {
        return data[x + y*width];
    }
    void draw_circle(int radius, const Vector2i& center, const Color& color)
    {
        std::function<int(int, int)> min = [](int a, int b) {return a > b ? b : a;};
        std::function<int(int, int)> max = [](int a, int b) {return a > b ? a : b;};
        for (int j = max(center.y - radius, 0); j < min(center.y + radius, height); j++)
        {
            for (int i = max(center.x - radius, 0); i < min(center.x + radius, width); i++)
            {
                if ((i - center.x) * (i - center.x) + (j - center.y) * (j - center.y) < radius * radius)
                    data[i + j*width] = color;
            }
        }
    }

    void draw_line(float x1, float y1, float x2, float y2, const Color& color)
    {
        // Bresenham's line algorithm
        const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
        if(steep)
        {
            std::swap(x1, y1);
            std::swap(x2, y2);
        }
     
        if(x1 > x2)
        {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }
     
        const float dx = x2 - x1;
        const float dy = fabs(y2 - y1);

        float error = dx / 2.0f;
        const int ystep = (y1 < y2) ? 1 : -1;
        int y = (int)y1;
     
        const int max_x = (int)x2;
     
        for(int x = (int)x1; x <= max_x; x++)
        {
            if(steep)
                set_pixel({y, x}, color);
            else
                set_pixel({x, y}, color);

            error -= dy;
            if(error < 0)
            {
                y += ystep;
                error += dx;
            }
        }
    }

    void draw_line(const Vector2i& p1, const Vector2i& p2, const Color& color)
    {
        draw_line(p1.x, p1.y, p2.x, p2.y, color);
    }

    // Установить цвет пикселя с координатами position
    void set_pixel(const Vector2i& position, const Color& color)
    {
        int id = position.x + position.y*width;
        if (id >= 0 && id < width * height)
            data[position.x + position.y*width] = color;
    }

    // Вернуть пиксель с координатами position
    Color get_pixel(const Vector2i& position) const
    {
        return data[position.x + position.y*width];
    }
};
