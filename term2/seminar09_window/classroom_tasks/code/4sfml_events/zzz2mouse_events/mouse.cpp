#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Программа, которая демонстрирует обработку событий, связанных с мышью

// Функция проверки столкновения точки с прямоугольником
bool check_point_rect_collision(const sf::Vector2i& p, const sf::RectangleShape& rect)
{
    sf::Vector2f left_top_point = rect.getPosition() - rect.getOrigin();
    float left_x = left_top_point.x;
    float right_x  = left_top_point.x + rect.getSize().x;
    float left_y = left_top_point.y;
    float right_y  = left_top_point.y + rect.getSize().y;
    if (p.x > left_x && p.x < right_x && p.y > left_y && p.y < right_y)
        return true;
    return false;
}

int main()
{
    srand(time(0));
    // Создаём экземпляр класса окно
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Key handling", sf::Style::Default, settings);
    window.setFramerateLimit(60);


    // Создаём объект - круг
    float radius = 50;
    sf::CircleShape circle(radius);
    circle.setFillColor({54, 216, 95});
    circle.setPosition({150, 50});
    circle.setOrigin({radius, radius});
    
    // Создаём объект - прямоугольник
    sf::Color rect_color = {100, 200, 100};
    sf::Color rect_hover_color = {200, 100, 100};
    float width = 80, height = 160;
    sf::RectangleShape rectangle({width, height});
    rectangle.setFillColor(rect_color);
    rectangle.setPosition({450, 400});
    rectangle.setOrigin({width / 2, height / 2});

    // Основной цикл программы (1 итерация = 1 кадр)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Проверяем, является ли событие - событием нажатия на кнопку мыши
            // Обрабатывается при нажатии (1 раз при нажатии)
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Проверяем, что нажатая кнопки была правой
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    // Можно узнать координаты мыши в момент нажатия
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    rectangle.setPosition({(float)event.mouseButton.x, (float)event.mouseButton.y});
                }
            }
            if (event.type == sf::Event::MouseMoved || event.type == sf::Event::MouseButtonPressed)
            {
                // Если точка положения мыши не прямоугольнике
                if (check_point_rect_collision(sf::Mouse::getPosition(window), rectangle))
                    rectangle.setFillColor(rect_hover_color);
                else
                    rectangle.setFillColor(rect_color);
            }
        }

        // Проверяем, зажата ли левая кнопка мыши
        // Разница с предыдущим способом (внутри цикла обработки событий)
        // заключается в том, что это проверка происходит каждый кадр
        // а событие - в момент нажатия кнопки
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // При зажатии левой кнопки мыши положение круга 
            // будет устанавливаться в место курсора 
            sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
            circle.setPosition({(float)mouse_position.x, (float)mouse_position.y});
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