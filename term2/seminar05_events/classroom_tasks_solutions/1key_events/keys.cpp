#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Программа, которая показывает как можно работать с обработкой событий
// нажатия на клавиши

int main()
{
    srand(time(0));
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key handling", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    // Создаём объект круга
    float radius = 50;
    sf::CircleShape circle(radius);
    circle.setFillColor({54, 216, 95});
    circle.setPosition({150, 50});
    circle.setOrigin({radius, radius});
    
    // создаём объект прямоугольника
    float width = 80, height = 160;
    sf::RectangleShape rectangle({width, height});
    rectangle.setFillColor({154, 16, 95});
    rectangle.setPosition({450, 400});
    rectangle.setOrigin({width / 2, height / 2});

    // Основной цикл программы (1 итерация = 1 кадр)
    while (window.isOpen())
    {
        // В этой части происходит обработка событий
        // События - нажатия на клавиши, движения мышью и другие
        // Все события, которые произошли за время с прошлого кадра
        // Сохраняются в специальной очереди, получить событие можно
        // с помощью метода pollEvent.
        // Этот метод принимает по ссылке объект event и задаёт
        // поля этого объекта, соответствующие следующему событию
        // pollEvent возвращает false, когда событий в очереди не останется
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Проверка, является ли событие - закрытием окна
            if (event.type == sf::Event::Closed)
                window.close();

            // Проверка, является ли событие - событием нажатия на клавишу
            // Обрабатывается при нажатии (1 раз во много кадров)
            
            if (event.type == sf::Event::KeyPressed)
            {
                // Проверяем, не является ли нажатая клавиша - клавишей G
                if (event.key.code == sf::Keyboard::G)
                {
                    std::cout << "the G key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                }

                if (event.key.code == sf::Keyboard::Enter)
                {
                    circle.setFillColor({(unsigned char)rand(), 
                        (unsigned char)rand(), (unsigned char)rand()});
                }
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Enter)
                {
                    rectangle.setFillColor({(unsigned char)rand(), 
                        (unsigned char)rand(), (unsigned char)rand()});
                }
            }
        }

        // Проверяем, нажата ли клавиша стрелочка вправо
        // Разница с предыдущим способом (внутри цикла обработки событий)
        // заключается в том, что это проверка происходит каждый кадр
        // а событие - в момент нажатия клавиши
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            circle.move(2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            circle.move(-2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            circle.move(0, 2);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            circle.move(0, -2);
        }
        window.clear(sf::Color::Black);

        // рисуем круг на скрытом холсте
        window.draw(circle);
        window.draw(rectangle);

        // отображаем содержимое скрытого холста на экран
        window.display();
    }

    return 0;
}