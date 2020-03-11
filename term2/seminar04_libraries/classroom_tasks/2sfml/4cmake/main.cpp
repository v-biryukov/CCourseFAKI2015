#include <SFML/Graphics.hpp>

/* Создайте специальную папку, в которой вы будете собирать ваш проект
    Например, папку build и перейдите в неё
    
    Вызовите cmake так:                        cmake <директория, где находится CMakeLists.txt файл>
    Если вы находитесь в папке build, то так:  cmake ..
    
    Чтобы задать конфигурацию:
        Linux                       cmake ..
        Windows MinGW:              cmake -G "MinGW Makefiles" ..
        Windows Visual Studio:      cmake -G "Visual Studio 16 2019" .. 

    Чтобы посмотреть все конфигурации: cmake -h

    В результате получится make-файл либо проект Visual Studio
    Чтобы его скомпилировать:
        Linux                       make
        Windows MinGW:              mingw32-make
        Windows Visual Studio:      Открыть .sln файл и скомпилировать
*/


int main()
{
    // Создаём экземпляр класса окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::CircleShape a(50.0f);
    a.setFillColor({54, 216, 95});
    a.setPosition({154, 56});
    // Главный цикл программы (1 итерация = 1 кадр)
    while (window.isOpen())
    {
        // В начале каждой итерации обрабатываем все события
        // (нажатие клавиш, движение мыши и другое)
        sf::Event event;
        while (window.pollEvent(event))
        {
            // В данном примере проверяем окно на закрытие
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очистить скрытый холст черным цветом
        window.clear(sf::Color::Black);

        a.move({0.1, 0.1});
        // рисуем круг на скрытом холсте
        window.draw(a);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}