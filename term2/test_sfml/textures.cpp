#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1728, 1080), "Textures");
    window.setFramerateLimit(60);

    // Создаём и открываем текстуру
    sf::Texture t;
    if (!t.loadFromFile("./graphics/skeleton_walk.png"))
    {
        std::cout << "Can't load image" << std::endl;
        exit(1);
    }

    sf::Texture background;
    if (!background.loadFromFile("./graphics/background.png"))
    {
        std::cout << "Can't load image" << std::endl;
        exit(1);
    }

    sf::Sprite fon;
    fon.setTexture(background);
    fon.setTextureRect({ 0, 0, 1728, 1080 });
    fon.setPosition({ 0, 0 });

    sf::Vector2f pos({ 0, 440 });
    sf::Sprite skeleton;           //skeleton
    skeleton.setTexture(t);
    skeleton.setScale({ 7, 7 });
    skeleton.setTextureRect({ 0, 0, 22, 33 });

    //({ 15, 79, 20, 19 }) - ring
    /*     HOUSE AND TREES
    // Создаём спрайт (специальный объект, который может быть покрыт текстурой)
    sf::Sprite sprite;           //house
    sprite.setTexture(t);

    // Задаём положение 'окошка' на текстуре для спрайта
    // 100, 100 - координаты верхнего левого угла 'окошка' на текстуре
    // 300, 400 - размеры 'окошка'
    sprite.setTextureRect({ 90, 45, 160, 120 });


    // Задаём положение самого спрайта
    sprite.setPosition({ 20, 100 });

    //Trees:
    sf::Sprite tr1;
    tr1.setTexture(t);
    tr1.setTextureRect({ 0, 0, 100, 200 });
    tr1.setPosition({ 200, 20 });

    sf::Sprite tr2;
    tr2.setTexture(t);
    tr2.setTextureRect({ 0, 0, 100, 200 });
    tr2.setPosition({ 310, 20 });

    sf::Sprite tr3;
    tr3.setTexture(t);
    tr3.setTextureRect({ 0, 0, 100, 200 });
    tr3.setPosition({ 420, 20 });
    */

    float time = 0;
    int x = 0;     //skeleton x coordinate
    int frame = 0;
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }

        }
    
        /*   //JUST MOVEMENT (task 4)
        if (frame % 60 == 0)
        {
            x += 22;
            if (x >= 286)
                x = 0;
            skeleton.setTextureRect({ x, 0, 22, 33 });
        }

        pos.x += 0.3 + (rand()%100)/500;
        if (pos.x > window.getSize().x)
            pos.x = 0;
        
        skeleton.setPosition(pos);
        */
        float skeleton_speed = 7;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {

            pos.x += skeleton_speed;
            x += 22;
            if (pos.x > window.getSize().x)
            {
                pos.x = 0;
                pos.y = 440;
            }
            if (pos.x < 0)
                pos.x = window.getSize().x;
            if (pos.x >= 480)               //jump
                pos.y = 720;
            if (x >= 286)
                x = 0;
            if (x < 0)
                x = 286;

            skeleton.setTextureRect({ x, 0, 22, 33 });
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            
            pos.x -= skeleton_speed;
            
            if (pos.x > window.getSize().x)
                pos.x = 0;
            if (pos.x < 0)
            {
                pos.x = window.getSize().x;
                pos.y = 720;
            }
            if (pos.x <= 480)                   //jump
                pos.y = 440;

            x -= 22;
            if (x >= 264)
                x = 0;
            if (x < 0)
                x = 264;

            skeleton.setTextureRect({ x + 22, 0, -22, 33 });
        }

        skeleton.setPosition(pos);

        window.draw(fon);
        window.draw(skeleton);
        //window.draw(tr1);
        //window.draw(tr2);
        //window.draw(tr3);
        window.display();

        time += 1.0 / 60;
        frame++;
    }
    

    return EXIT_SUCCESS;
}


// Задание 1: 
// Загрузите текстуру graphics/items.png и нарисуйте на экране колечко (5 строка, 2 столбец)
// Увеличьте это колечко в 10 раз (.setScale({10, 10}))

// Задание 2: 
// Загрузите текстуру graphics/props.png и нарисуйте на экране дом и 3 дерева
// (текстуру нужно загружать только один раз)

// Задание 3: 
// Загрузите текстуру graphics/skeleton_walk.png и нарисуте первый кадр скелета

// Задание 4:
// Создайте анимацию движения скелета. Для этого меняйте 'окошко' спрайта на текстуре
// каждые несколько кадров (скорость анимации нужно подобрать самим)

// Задание 5: 
// Загрузите текстуру graphics/background.png и нарисуйте её на всей области экрана

// Задание 6: 
// Сделайте так, чтобы скелет ходил по нажатию клавиш
// Для того, чтобы отобразить обратное движение, можно просто в функции setTextureRect
// задать отрицательные числа