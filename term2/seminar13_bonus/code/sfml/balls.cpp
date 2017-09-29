#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

int windowWidth = 800, windowHeight = 600;

class Ball
{
public:
	CircleShape shape;
    float vx, vy;
    float radius;


    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float top() { return y() - shape.getRadius(); }
    float bottom() { return y() + shape.getRadius(); }

    Ball(float x, float y, float vx, float vy, float radius)
    {
    	this->vx = vx;
    	this->vy = vy;
    	shape.setPosition(x, y);
        shape.setRadius(radius);
        shape.setFillColor(Color::White);
        shape.setOrigin(radius, radius);
    }

    void update()
    {
        shape.move(vx, vy);
        cout << vx << endl;

        if(left() < 0)
            vx *= -1;
        else if(right() > windowWidth)
            vx *= -1;

        if(top() < 0)
            vy *= -1;
        else if(bottom() > windowHeight)
            vy *= -1;
    }

};


int main()
{
    Ball ball = Ball(windowWidth / 2, windowHeight / 2, 20, 20, 20);


    vector<Ball> balls;
    for (int i = 0; i < 10; ++i)
    	balls.push_back(Ball(50*i, 30*i, 4*i, 10-3*i, 20));


	RenderWindow window(VideoMode(800, 600), "Balls");
    window.setFramerateLimit(60);

    while(true)
    {
        window.clear(Color::Black);

        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) 
        	break;

        ball.update();
        window.draw(ball.shape);

        for (int i = 0; i < 10; ++i)
        {
        	balls[i].update();
        	window.draw(balls[i].shape);
        }

        window.display();
    }

    return 0;
}