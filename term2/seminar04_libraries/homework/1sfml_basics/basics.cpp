#include <SFML/Graphics.hpp>

int main()
{
    // Создаём экземпляр класса RenderWindow
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // Создаём экземпляр класса CircleShape и задаём поля ( круг радиуса 50 )
    sf::CircleShape a(50.0f);
    a.setFillColor({54, 216, 95});
    a.setPosition({154, 56});
    // Главный цикл программы (1 итерация = 1 кадр)
    while (window.isOpen())
    {
        // В начале каждой итерации обрабатываем все события
        // ( нажатие клавиш, движение мыши и другое )
        sf::Event event;
        while (window.pollEvent(event))
        {
            // В данном примере проверяем окно на закрытие
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // очистить скрытый холст черным цветом
        window.clear(sf::Color::Black);

        // передвинуть круг a на {0.1, 0.1}
        a.move({0.1, 0.1});
        // рисуем круг на скрытом холсте
        window.draw(a);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }
}