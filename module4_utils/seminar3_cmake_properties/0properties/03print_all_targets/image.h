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

        Color& operator+=(Color c);
        Color operator+(Color c) const;
    private:
        unsigned char saturateCast(int a);
    };

    Image();
    Image(const std::string& filename);
    Image(int width, int height);
    Image(int width, int height, Color c);

    int getWidth() const {return mWidth;}
    int getHeight() const {return mHeight;}
    unsigned char* getData() {return mData.data();}

    void setPixel(int i, int j, Color c);
    Color getPixel(int i, int j) const;

    void loadPpm(const std::string& filename);
    void savePpm(const std::string& filename) const;

    void drawCircle(int radius, int centerX, int centerY, Color c);
    void drawLine(int x1, int y1, int x2, int y2, Color c);
};