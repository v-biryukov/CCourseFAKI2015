/*
    Класс изображения

    Класс Image из данного файла - это простейший класс для работы с изображениями в формате PPM P6.
    
    Поля класса Image:

        mWidth  -   ширина изображения в пикселях
        mHeigth -   высота изображения в пикселях
        mData   -   здесь хранятся цвета всех пикселей по цветовой модели RGB.
                    Цвет описывается тремя однобайтовыми числами (красная, зелёная и синяя компоненты)
                    Соответственно размер этого массива равен  3 * mWidth * mHeight.

    Внутренний класс Color - вспомогательный класс, для хранения цвета.

    
    Методы класса Image:

        Image(const std::string& filename)      -   конструктор, которому передаётся название файла изображения.
                                                    Это изображение считывается и создаётся объект класса Image,
                                                    хранящий это изображение.


        Image(int width, int height)            -   создаёт изображение размера width на height черного цвета.
        Image(int width, int height, Color c)   -   создаёт изображение размера width на height цвета c.
        getWidth, getHeight, getData            -   геттеры для полей класса

        setPixel(int i, int j, Color c)         -   задать цвет пикселя с координатами (i, j) цветом c
        getPixel(int i, int j)                  -   получить цвет пикселя с координатами (i, j)

        loadPpm(const std::string& filename)    -   загрузить картинку в формате PPM из файла под названием filename
        savePpm(const std::string& filename)    -   сохранить картинку в формате PPM в файл под названием filename

        drawCircle(int radius, int centerX, int centerY, Color c) 
                                                -   нарисовать на картинке круг радиусом radius с центром 
                                                    в пикселе (centerX, centerY) цветом c.


        drawLine(int x1, int y1, int x2, int y2, Color c)  
                                                -   нарисовать на картинке отрезок от пикселя (x1, y1) до
                                                    пикселя (x2, y2) цветом c.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cassert>


class Image
{
private:
    int mWidth  {0};
    int mHeight {0};
    std::vector<unsigned char> mData {};

public:

    class Color
    {
    public:
        unsigned char r, g, b;

        Color& operator+=(Color c) 
        {
            r = saturateCast(r + c.r);
            g = saturateCast(g + c.g);
            b = saturateCast(b + c.b);
            return *this;
        }

        Color operator+(Color c) const
        {
            Color result = *this;
            result += c;
            return result;
        }

    private:

        unsigned char saturateCast(int a)
        {
            if (a > 255)
                a = 255;
            else if (a < 0)
                a = 0;
            return static_cast<unsigned char>(a);
        }
        
    };

    Image() {}

    Image(const std::string& filename)
    {
        loadPpm(filename);
    }

    Image(int width, int height) : mWidth(width), mHeight(height)
    {
        mData.resize(3 * mWidth * mHeight);
        std::fill(mData.begin(), mData.end(), 0);
    }

    Image(int width, int height, Color c) : mWidth(width), mHeight(height)
    {
        mData.resize(3 * mWidth * mHeight);
        for (int j = 0; j < mHeight; ++j)
        {
            for (int i = 0; i < mWidth; ++i)
            {
                setPixel(i, j, c);
            }
        }
    }


    int getWidth() const {return mWidth;}
    int getHeight() const {return mHeight;}
    unsigned char* getData() {return mData.data();}


    void setPixel(int i, int j, Color c)
    {
        assert(i >= 0 && i < mWidth && j >= 0 && j < mHeight);

        mData[3 * (j * mWidth + i) + 0] = c.r;
        mData[3 * (j * mWidth + i) + 1] = c.g;
        mData[3 * (j * mWidth + i) + 2] = c.b;
    }

    Color getPixel(int i, int j) const
    {
        assert(i >= 0 && i < mWidth && j >= 0 && j < mHeight);

        size_t index = j * mWidth + i;
        return {mData[3 * index + 0], mData[3 * index + 1], mData[3 * index + 2]};
    }


    void loadPpm(const std::string& filename)
    {
        std::ifstream in {filename, std::ios::binary};
        if (in.fail())
        {
            std::cout << "Error. Can't open file!" << std::endl;
            std::exit(1);
        }

        std::string type;
        in >> type;
        if (type != "P6")
        {
            std::cout << "Error. File should be type P6 .ppm file!" << std::endl;
            std::exit(1);
        }

        in >> mWidth >> mHeight;

        int maxValue;
        in >> maxValue;

        char temp;
        in >> std::noskipws >> temp;

        mData.resize(3 * mWidth * mHeight);
        in.read(reinterpret_cast<char*>(&mData[0]), mData.size());
    }

    void savePpm(const std::string& filename) const
    {
        std::ofstream out {filename, std::ios::binary};
        out << "P6\n" << mWidth << " " << mHeight << "\n255\n";
        out.write(reinterpret_cast<const char*>(&mData[0]), mData.size());
    }


    void drawCircle(int radius, int centerX, int centerY, Color c)
    {
        for (int j = std::max(centerY - radius, 0); j <std:: min(centerY + radius, mHeight); j++)
        {
            for (int i = std::max(centerX - radius, 0); i < std::min(centerX + radius, mWidth); i++)
            {
                if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) < radius * radius)
                    setPixel(i, j, c);
            }
        }
    }

    void drawLine(int x1, int y1, int x2, int y2, Color c)
    {
        bool steep = (std::fabs(y2 - y1) > std::fabs(x2 - x1));
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
     
        int dx = x2 - x1;
        int dy = std::fabs(y2 - y1);

        int error = dx / 2;
        int ystep = (y1 < y2) ? 1 : -1;
        int y = y1;
        int maxX = x2;
     
        for(int x = x1; x <= maxX; x++)
        {
            if(steep)
                setPixel(y, x, c);
            else
                setPixel(x, y, c);

            error -= dy;
            if(error < 0)
            {
                y += ystep;
                error += dx;
            }
        }
    }

};



int main()
{
    Image im(400, 400);

    im.drawCircle(100, 200, 200, {200, 100, 100});

    im.drawLine(100, 100, 200, 300, {255, 255, 0});
    im.drawLine(100, 100, 280, 300, {255, 255, 0});
    im.drawLine(100, 100, 360, 300, {255, 255, 0});

    im.savePpm("result.ppm");
}