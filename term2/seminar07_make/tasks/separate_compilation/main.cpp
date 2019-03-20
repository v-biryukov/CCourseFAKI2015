#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

class Complex         // класс "Комплексное число"
{
private:
    double re, im;      // действительная и мнимая части

public:
    // конструкторы 
    Complex (){};

    Complex (double re0)   
    {
        re = re0;
        im = 0;
    }

    Complex (double re0, double im0)
    {
        re = re0;
        im = im0;
    }

    Complex (const Complex& c)   // конструктор копирования
    {
        re = c.re;
        im = c.im;
    }

    // деструктор
    ~Complex (){}

    // остальные функции

    // Модуль комплексного числа
    double abs ()        
    {
        return sqrt(re * re + im * im);
    }

    // оператор присваивания
    Complex& operator= (const Complex &c)   
    {
        re = c.re;
        im = c.im;
        return (*this);
    }

    // оператор +=
    Complex& operator+= (Complex &c)   
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    // оператор сложения
    Complex operator+ (const Complex &c)   
    {
        return Complex (re + c.re, im + c.im);
    }

    // оператор вычитания
    Complex operator- (const Complex &c)   
    {
        return Complex(re - c.re, im - c.im);
    }

    // оператор умножения
    Complex operator* (const Complex &c)   
    {
        return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
    }

    // оператор деления
    Complex operator / (const Complex &c)   
    {
        Complex temp;

        double norm = c.re * c.re + c.im * c.im;
        temp.re = (re * c.re + im * c.im) / norm;
        temp.im = (im * c.re - re * c.im) / norm;
        return temp;
    }


    // Унарный оператор -
    // То есть если z - комплексное число x + iy, то *z = - x - iy
    Complex operator-()
    {
        Complex result(-re, -im);
        return result;
    }

    // Унарный оператор +
    // Ничего не делает
    Complex operator+()
    {
        return *this;
    }

    // Унарный оператор *
    // То есть если z - комплексное число x + iy, то *z = x - iy
    Complex operator*()
    {
        Complex result(re, -im);
        return result;
    }

    // укажем дружественные операторы, которым мы разрешаем доступ
    // к личным (private) данным
    friend std::ostream& operator<< (std::ostream &, const Complex &);   
    friend std::istream& operator>> (std::istream &, Complex &);  

    // дружественные операторы сложения/умножения обычного числа на комплексное
    // (в таком порядке)
    friend Complex operator+(double first, const Complex& second);
    friend Complex operator*(double first, const Complex& second);
};

// перегрузка оператора <<
std::ostream& operator<< (std::ostream &out, const Complex &c)
{
    if (c.re != 0)
        out << c.re;

    if (c.im > 0)
    {
        if (c.im != 1.0)
            out << " + " << c.im << "i";
        else
            out << " + i";
    }
    else if (c.im < 0)
    {
        if (c.im != -1.0)
            out << " - " << -c.im << "i";
        else
            out << " - i";
    }
    return out;
}

// перегрузка оператора >>
std::istream& operator>> (std::istream &in, Complex &c)
{
    in >> c.re >> c.im;
    return in;
}

// Число + комплексное число (в таком порядке)
Complex operator+(double first, const Complex& second)
{
    Complex result(second);
    result.re += first;
    return result;
}

// Число * комплексное число (в таком порядке)
Complex operator*(double first, const Complex& second)
{
    Complex result(second);
    result.re *= first;
    result.im *= first;
    return result;
}



// Класс пикселя
struct Pixel
{
    // Цвет пикселя кодируется 3-мя числами от 0 до 255
    unsigned char r, g, b;

    // 2 конструктора
    Pixel(){};
    Pixel(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {};

    // оператор присваивания
    Pixel& operator = (const Pixel &c)   
    {
        r = c.r;
        g = c.g;
        b = c.b;
        return (*this);
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
    Image()
    {
        data = NULL;
    }
    // Конструктор, который создает экземпляр картинки, считывая её из файла
    Image(const char* filename)
    {
        data = NULL;
        read(filename);
    }
    // Конструктор, который создаёт черную картинку размера size_x x size_y
    Image(int size_x, int size_y) : size_x(size_x), size_y(size_y)
    {
        data = (Pixel*)calloc(size_x * size_y, sizeof(Pixel));
    }

    // Деструктор, нужно не забыть освободить память
    ~Image()
    {
        if (data)
            free(data);
    }


    int get_size_x()
    {
        return size_x;
    }

    int get_size_y()
    {
        return size_y;
    }

    // Чтение/запись картинки из файла
    void read(const char *filename)
    {
        if (data != NULL)
        {
            free(data);
        }
        char buff[16];

        FILE *fp;
        int c, rgb_comp_color;
        //open PPM file for reading
        fp = fopen(filename, "rb");
        if (!fp) 
        {
            fprintf(stderr, "Unable to open file '%s'\n", filename);
            exit(1);
        }

        //read image format
        if (!fgets(buff, sizeof(buff), fp)) 
        {
            perror(filename);
            exit(1);
        }

        //check the image format
        if (buff[0] != 'P' || buff[1] != '6') 
        {
             fprintf(stderr, "Invalid image format (must be 'P6')\n");
             exit(1);
        }

        //check for comments
        c = getc(fp);
        while (c == '#') 
        {
            while (getc(fp) != '\n') ;
                c = getc(fp);
        }

        ungetc(c, fp);
        //read image size information
        if (fscanf(fp, "%d %d", &size_x, &size_y) != 2) 
        {
             fprintf(stderr, "Invalid image size (error loading '%s')\n", filename);
             exit(1);
        }

        //read rgb component
        if (fscanf(fp, "%d", &rgb_comp_color) != 1) {
             fprintf(stderr, "Invalid rgb component (error loading '%s')\n", filename);
             exit(1);
        }

        //check rgb component depth
        if (rgb_comp_color!= 255) {
             fprintf(stderr, "'%s' does not have 8-bits components\n", filename);
             exit(1);
        }

        while (fgetc(fp) != '\n') ;
        //memory allocation for pixel data
        data = (Pixel*)malloc(size_x * size_y * sizeof(Pixel));

        //read pixel data from file
        if (fread(data, 3 * size_x, size_y, fp) != size_y) 
        {
             fprintf(stderr, "Error loading image '%s'\n", filename);
             exit(1);
        }

        fclose(fp);
    }
    void write(const char *filename)
    {
        FILE *fp;
        //open file for output
        fp = fopen(filename, "wb");
        if (!fp) 
        {
             fprintf(stderr, "Unable to open file '%s'\n", filename);
             exit(1);
        }

        //write the header file
        //image format
        fprintf(fp, "P6\n");

        //image size
        fprintf(fp, "%d %d\n", size_x, size_y);

        // rgb component depth
        fprintf(fp, "%d\n", 255);

        // pixel data
        fwrite(data, 3 * size_x, size_y, fp);
        fclose(fp);
    }
    
    // Функция, которая обращает цвета картинки
    void reverse_colors()
    {
        if(data)
        {
             for(int i=0; i< size_x*size_y; i++)
             {
                  data[i].r = 255 - data[i].r;
                  data[i].g = 255 - data[i].g;
                  data[i].b = 255 - data[i].b;
             }
        }
    }   
    // Функция, которая зеркально отображает картинку
    void flip_vertically()
    {
        Pixel temp;
        if(data)
        {
            for(int j = 0; j < size_y/2; j++)
            {
                for(int i = 0; i < size_x; i++)
                {
                    
                    temp = data[i+j*size_x];
                    data[i+j*size_x] = data[i+(size_y-j-1)*size_x];
                    data[i+(size_y-j-1)*size_x] = temp;
                }
            }
        }
    }

    // Установить цвет пикселя с координатами (x, y)
    void set_pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
    {
        data[x + y*size_x] = Pixel(r, g, b);
    }
    void set_pixel(int x, int y, const Pixel& p)
    {
        data[x + y*size_x] = p;
    }
    Pixel get_pixel(int x, int y)
    {
        return data[x + y*size_x];
    }
};




int main()
{
    Complex a (1, 4);
    Complex b (5, 2);
    std::cout << a << " / " << b << " = " << a / b << std::endl;


    Image myimage;
    myimage.read("emir.ppm");
    myimage.reverse_colors();
    myimage.flip_vertically();
    myimage.write("myimage.ppm");
}