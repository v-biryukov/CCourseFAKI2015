#include <SFML/Graphics.hpp>

/* Для компиляции используйте команду:
	g++ .\main.cpp -I ..\..\..\..\3rdparty\SFML-2.5.1\include\ -L ..\..\..\..\3rdparty\SFML-2.5.1\lib\ -lsfml-graphics -lsfml-window -lsfml-system
	Опции:
		-I <путь до папки с хедерами (.h файлами)>
			В нашем случае это cs_mipt_faki\term2\3rdparty\SFML-2.5.1\include
		-L <путь до папки со скомпилированными библиотеками>
			В нашем случае это cs_mipt_faki\term2\3rdparty\SFML-2.5.1\lib

		-l<имя файла статической библиотеки, которую нужно подключить (без расширения и префикса lib)>
			В папке cs_mipt_faki\term2\3rdparty\SFML-2.5.1\lib должны лежать файлы
			libsfml-graphics.a, libsfml-window.a и libsfml-system.a
*/

int main()
{
    // Создаём экземпляр класса окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // Создаём экземпляр фигуры-круга, задаём его цвет и координаты центра
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

        // Двигаем кружок
        a.move({0.1, 0.1});
        // рисуем круг на скрытом холсте
        window.draw(a);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}