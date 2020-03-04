#include <SFML/Graphics.hpp>

// Linux
/* Для компиляции на Linux используйте команду:
	./build.sh

    Файл build.sh должен быть исполняемым.
    (Иметь права доступа для исполнения)
    - Посмотреть права доступа можно командой:
        ls -l

    Если этот файл не исполняемый, то его можно сделать исполняемым командой:
        chmod +x ./build.sh
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