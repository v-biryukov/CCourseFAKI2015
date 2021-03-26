#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define M_PI 3.1415926536


// Вспомагательная функция для скалярного произведения векторов типа sf::Vector2f
float operator*(const sf::Vector2f& first, const sf::Vector2f& second)
{
    return first.x*second.x + first.y*second.y;
}


// Описываем все классы, которые мы будем использовать в программе
// Это нужно сделать так как даже определение одного класса может зависеть от другого
// Например, класс Bonus зависит от класса Arkanoid и наоборот
struct Ball;
struct Block;
class Arkanoid;



class Bonus
{
private:
    static const float speed;
    sf::Vector2f position;
    float time;

public:
    Bonus(sf::Vector2f position);
    void update(float dt);
    void draw(sf::RenderWindow& window, Arkanoid& game) const;
    void activate(Arkanoid& game);

    // Класс Arkanoid должен быть дружественным, так как он может менять внутреннее объекта-бонуса
    friend class Arkanoid;
};



struct Ball
{
    sf::Vector2f position;
    sf::Vector2f velocity;
};

struct Block
{
    float width, height;
    sf::Vector2f position;
};




class Arkanoid
{
private:
    // Время, которое прошло с начала игры
    float time;
    // Границы игрового поля
    float left, right, bottom, top;
    
    // Цвета
    sf::Color  ball_color;
    sf::Color  paddle_color;
    sf::Color  block_color;

    // Фигуры для рисования, для рисования всех блоков - 1 фигура
    sf::CircleShape ball_shape;
    sf::RectangleShape paddle_shape;
    sf::RectangleShape block_shape;


    float ball_radius;
    float ball_speed;
    // Связыный список всех шариков
    std::list<Ball> balls;

    float block_width, block_height;
    // Связыный список всех блоков
    std::list<Block> blocks;

    // Ракетка
    Block paddle;
    // Переменная, которая показывает находится ли шарик на ракетке
    // В начале игры, или после того, как все шары упали
    bool is_stack;

    // Число жизней
    int number_of_lives;

    // Связный список указателей на бонусы
    // Почему указатели - для реализации полиформизма
    // Так как в будущем мы хотим сделать несколько вариантов бонусов
    std::list<Bonus*> bonuses;

    // Вероятность того, что при разрушении блока выпадет бонус
    float bonus_probability;



    float norm(sf::Vector2f a) const
    {
        return sqrtf(a.x * a.x + a.y * a.y);
    }

    float sqnorm(sf::Vector2f a) const
    {
        return a.x * a.x + a.y * a.y;
    }

    // Функция, которая ищет вектор от центра шарика до ближайшей точки блока
    sf::Vector2f find_closest_point(const Ball& ball, const Block& block) const
    {
        float rect_left   = block.position.x - block.width/2;
        float rect_right  = block.position.x + block.width/2;
        float rect_bottom = block.position.y - block.height/2;
        float rect_top    = block.position.y + block.height/2;
        sf::Vector2f d;
        if (ball.position.x < rect_left)
            d.x = rect_left;
        else if (ball.position.x > rect_right)
            d.x = rect_right;
        else
            d.x = ball.position.x;

        if (ball.position.y < rect_bottom)
            d.y = rect_bottom;
        else if (ball.position.y > rect_top)
            d.y = rect_top;
        else
            d.y = ball.position.y;

        d -= ball.position;

        return d;
    }

    // Удаляем блок по итературу и создаём бонус с некоторой вероятностью
    void erase_block(std::list<Block>::iterator block_iterator)
    {
        int max_rand = 10000;
        if ((rand() % max_rand) * 1.0f / max_rand < bonus_probability)
        {
            bonuses.push_back(new Bonus((*block_iterator).position));
        }
        blocks.erase(block_iterator);   
    }

    // Обрабатываем столкновения шарика со всеми блоками
    void handle_blocks_collision(Ball& ball)
    {
        // Ищем ближайшую точку до блоков
        // Перебираем все блоки - это не самая эффективная реализация,
        // Можно написать намного быстрее, но не так просто
        sf::Vector2f closest_point = {10000, 10000};
        std::list<Block>::iterator closest_iterator;
        for (std::list<Block>::iterator it = blocks.begin(); it != blocks.end(); it++)
        {
            sf::Vector2f current_closest_point = find_closest_point(ball, *it);
            if (sqnorm(current_closest_point) < sqnorm(closest_point))
            {
                closest_point = current_closest_point;
                closest_iterator = it;
            }
        }

        float closest_point_norm = norm(closest_point);
        // Если расстояние == 0, то это значит, что шарик за 1 фрейм зашёл центром внутрь блока
        // Отражаем шарик от блока
        if (closest_point_norm < 1e-4)
        {
            if (fabs(ball.velocity.x) > fabs(ball.velocity.y))
                ball.velocity.x *= -1;
            else
                ball.velocity.y *= -1;

            erase_block(closest_iterator);  

        }
        // Если расстояние != 0, но шарик касается блока, то мы можем просчитать отражение более точно
        // Отражение от углов и по касательной.
        else if (sqnorm(closest_point) < ball_radius * ball_radius)
        {
            ball.position -= closest_point * ((ball_radius - closest_point_norm) / closest_point_norm);
            ball.velocity -= 2.0f * closest_point * (closest_point * ball.velocity) / (closest_point_norm*closest_point_norm);
            erase_block(closest_iterator);           
        }
    }

    // Обрабатываем столкновения шарика с ракеткой
    void handle_paddle_collision(Ball& ball) const
    {
        if (ball.position.y + ball_radius > paddle.position.y - paddle.height/2 &&
            ball.position.y - ball_radius < paddle.position.y + paddle.height/2)
        {
            if (ball.position.x + ball_radius > paddle.position.x - paddle.width/2 &&
                ball.position.x - ball_radius < paddle.position.x + paddle.width/2)
            {
                // Угол отражения зависит от места на ракетке, куда стукнулся шарик
                float velocity_angle = (ball.position.x - paddle.position.x) / (paddle.width + 2 * ball_radius) * (0.8*M_PI) + M_PI/2;
                float velocity_norm = norm(ball.velocity);
                ball.velocity.x = -velocity_norm * cosf(velocity_angle);
                ball.velocity.y = -velocity_norm * sinf(velocity_angle);
            }
        }
    }

    // Обрабатываем столкновения шарика со стенами
    void handle_wall_collision(Ball& ball) const
    {
        if (ball.position.x < left + ball_radius)
        {
            ball.position.x = left + ball_radius;
            ball.velocity.x *= -1;
        }
        if (ball.position.x > right - ball_radius)
        {
            ball.position.x = right - ball_radius;
            ball.velocity.x *= -1;
        }
        if (ball.position.y < bottom + ball_radius)
        {
            ball.position.y = bottom + ball_radius;
            ball.velocity.y *= -1;
        }
    }

    // Функция, которая обрабатывает все столкновения шарика за 1 кадр
    void handle_all_collisions(Ball& current_ball) 
    {
        handle_wall_collision(current_ball);
        handle_blocks_collision(current_ball);
        handle_paddle_collision(current_ball);
    }


    void draw_ball(sf::RenderWindow& window, sf::Vector2f position)
    {
        ball_shape.setRadius(ball_radius);
        ball_shape.setOrigin(ball_radius, ball_radius);
        ball_shape.setFillColor(ball_color);
        ball_shape.setPosition(position);
        window.draw(ball_shape);
    }




public:
    Arkanoid(const sf::RenderWindow& window)
    {
        time = 0;

        left = 0;
        right = window.getSize().x;
        bottom = 0;
        top = window.getSize().y;

        ball_color = sf::Color(246, 213, 92);
        paddle_color = sf::Color::White;
        block_color = sf::Color(100, 200, 250);

        block_width = 40;
        block_height = 16;
        block_shape.setSize({block_width, block_height});

        paddle.width = 120;
        paddle.height = 20;
        paddle.position = {(right - left)/2, top - 100};
        paddle_shape.setSize({paddle.width, paddle.height});
        paddle_shape.setOrigin(paddle.width / 2, paddle.height / 2);

        ball_speed = 600;
        //balls.push_back({{500, 500}, {ball_speed, 400}});
        ball_radius = 8;

        is_stack = true;
        number_of_lives = 5;

        bonus_probability = 0.1;
    }

    void add_block(sf::Vector2f position)
    {
        blocks.push_back({block_width, block_height, position});
    }

    void add_ball(const Ball& ball)
    {
        balls.push_back(ball);
    }

    // Эта функция вызывается каждый кадр
    void update(const sf::RenderWindow& window, float dt)
    {
        time += dt;
        // Положение ракетки
        paddle.position.x = sf::Mouse::getPosition(window).x;

        // Обрабатываем шарики
        for (std::list<Ball>::iterator it = balls.begin(); it != balls.end();)
        {
            (*it).position += (*it).velocity * dt;
            handle_all_collisions(*it);
            if ((*it).position.y > top)
            {
                it = balls.erase(it);
            }
            else
            {
                it++;
            }
        }

        // Если шариков нет, то переходи в режим начала игры и уменьшаем кол-во жизней
        if (!is_stack && balls.size() == 0)
        {
            is_stack = true;
            number_of_lives--;
        }
        
        // Обрабатываем бонусы
        std::list<Bonus*>::iterator it = bonuses.begin();
        while (it != bonuses.end())
        {
            (*it)->update(dt);
            if ((*it)->position.y > paddle.position.y - paddle.height/2 && (*it)->position.y < paddle.position.y + paddle.height/2)
            {
                 if ((*it)->position.x > paddle.position.x - paddle.width/2 && (*it)->position.x < paddle.position.x + paddle.width/2)
                 {
                    (*it)->activate(*this);
                    delete (*it);
                    it = bonuses.erase(it);
                 }
            }
            else if ((*it)->position.y > top)
            {
                delete (*it);
                it = bonuses.erase(it);
            }
            else
            {
                it++;
            }
            
        }
    }

    void draw(sf::RenderWindow& window)
    {
        // Рисуем блоки
        for (const Block& block : blocks)
        {
            block_shape.setOrigin(block.width / 2, block.height / 2);
            block_shape.setPosition(block.position);
            block_shape.setFillColor(block_color);
            window.draw(block_shape);
        }

        // Рисуем шарики
        for (const Ball& ball : balls)
        {
            draw_ball(window, ball.position);
        }

        // Рисуем ракетку
        paddle_shape.setPosition(paddle.position);
        window.draw(paddle_shape);

        // Если мы в режиме начала игры, то рисуем шарик на ракетке
        if (is_stack)
        {
            draw_ball(window, {paddle.position.x, paddle.position.y - paddle.height/2 - ball_radius});
        }

        // Рисуем кол-во жизней вверху слева
        for (int i = 0; i < number_of_lives; i++)
        {
            draw_ball(window, {ball_radius * (3 * i + 2), 2 * ball_radius});
        }

        // Рисуем бонусы
        for (Bonus* pbonus : bonuses)
        {
            pbonus->draw(window, *this);
        }
    }


    // Функция, которая вызывается каждый кадр
    void on_mouse_pressed(sf::Event& event)
    {
        if (is_stack)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                is_stack = false;
                float velocity_angle = (rand() % 100 + 40) * M_PI / 180;
                float velocity_norm = ball_speed;
                sf::Vector2f new_ball_position = {paddle.position.x, paddle.position.y - paddle.height/2 - ball_radius};
                sf::Vector2f new_ball_velocity = {-velocity_norm * cosf(velocity_angle), -velocity_norm * sinf(velocity_angle)};
                add_ball({new_ball_position, new_ball_velocity});
            }
        }
    }

    // Класс бонус должен быть дружественным, так как он может менять внутреннее состояние игры
    friend class Bonus;
};



Bonus::Bonus(sf::Vector2f position): position(position)
{
    time = 0;
}

// Двигаем бонус
void Bonus::update(float dt)
{
    time += dt;
    position.y += speed * dt;
}

// Рисуем бонус
void Bonus::draw(sf::RenderWindow& window, Arkanoid& game) const
{
    // Рисуем белый круг
    float back_shape_radius = 16;
    sf::CircleShape testshape(back_shape_radius);
    testshape.setOrigin(back_shape_radius, back_shape_radius);
    testshape.setFillColor(sf::Color::White);
    testshape.setPosition(position);
    window.draw(testshape);
    float angle = time;

    // Рисуем 3 шарика на этом круге
    float ball_rotation_radius = 12;
    game.draw_ball(window, position + ball_rotation_radius * sf::Vector2f(cosf(angle), sinf(angle)));
    angle += 2.0 * M_PI / 3.0;
    game.draw_ball(window, position + ball_rotation_radius * sf::Vector2f(cosf(angle), sinf(angle)));
    angle += 2.0 * M_PI / 3.0;
    game.draw_ball(window, position + ball_rotation_radius * sf::Vector2f(cosf(angle), sinf(angle)));
}

// Применяем эффект бонуса (в данном случае - утроение шариков)
void Bonus::activate(Arkanoid& game)
{
    // Количество шариков до утроения
    int number_of_balls = game.balls.size();
    // Так как мы работаем со связным списком, то придётся использовать итератор
    std::list<Ball>::iterator ball_it = game.balls.begin();
    // Проходим итератором по изначальным элементам списка и добавляем новые шарики в список
    // В данном случае простой цикл через итераторы не сработает, так как
    // массив game.balls увеличивается в процессе выполнения цикла
    for (int i = 0; i < number_of_balls; i++)
    {
        // Выбираем случайный вектор скорости
        float random_angle = rand() % 1000 * (2 * M_PI / 1000);
        float velocity_x = game.ball_speed * sin(random_angle);
        float velocity_y = game.ball_speed * cos(random_angle);
        // Добавляем шарик в список game.balls
        game.add_ball({(*ball_it).position, {velocity_x, velocity_y}});

        // Делаем то же самое для ещё одного шарика
        random_angle = rand() % 1000 * (2 * M_PI / 1000);
        velocity_x = game.ball_speed * sin(random_angle);
        velocity_y = game.ball_speed * cos(random_angle);
        game.add_ball({(*ball_it).position, {velocity_x, velocity_y}});
        // Переходим ко следующему шарику в списке
        ball_it++;
    }
}

// Скорость бонусов
const float Bonus::speed = 100;


int main () 
{
    srand(time(0));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 800, 32), "Arkanoid", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    
    Arkanoid game(window);
    for(int i = 0; i < 21; ++i)
        for(int j = 0; j < 20; ++j) 
        {
            int stride_x = 40;
            int stride_y = 16;
            game.add_block({(float)((i + 1) * (stride_x + 3) + 22), {(float)((j + 2) * (stride_y +3))}});
        }
        

    while (window.isOpen()) 
    {
        // Обработка событий
        sf::Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                game.on_mouse_pressed(event);
            }
            if (event.type == sf::Event::KeyPressed)
            {
            }


        }
        window.clear(sf::Color(12, 31, 47));
        // Расчитываем новые координаты и новую скорость шарика
        game.update(window, 1.0f/60);
        game.draw(window);

        // Отображам всё нарисованное на временном "холсте" на экран
        window.display();
    }

    return EXIT_SUCCESS;
}
