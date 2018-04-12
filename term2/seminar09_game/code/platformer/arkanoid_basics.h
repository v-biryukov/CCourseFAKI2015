#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>


const int window_width = 800, window_height = 600;
const float ball_radius = 5.f, ball_velocity = 10.f;
const float paddle_width = 90.f, paddle_height = 20.f, paddle_velocity = 6.f;
const float block_width = 60.f, block_height = 20.f;
const sf::Color ball_color = sf::Color::White;
const sf::Color paddle_color = sf::Color::White;
const sf::Color brick_color = sf::Color::White;

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Ball(float x, float y) 
    {
        shape.setPosition(x, y);
        shape.setRadius(ball_radius);
        shape.setFillColor(ball_color);
        shape.setOrigin(ball_radius, ball_radius);
        velocity = sf::Vector2f(-ball_velocity, -ball_velocity);
    }

    void update () 
    { 
        // Двигаем шарик
        shape.move (velocity); 

        // Учитываем столкновения со стенками
        if (left() < 0 )
        {
            velocity.x *= -1;
            shape.setPosition(shape.getRadius(), shape.getPosition().y);
        }
        else if (right() > window_width)
        {
            velocity.x *= -1;
            shape.setPosition(window_width - shape.getRadius(), shape.getPosition().y);
        }
        if (top() < 0)
        {
            velocity.y *= -1;
            shape.setPosition(shape.getPosition().x, shape.getRadius());
        }
    }

    float x()           { return shape.getPosition().x; }
    float y()           { return shape.getPosition().y; }
    float left()        { return x() - shape.getRadius(); }
    float right()       { return x() + shape.getRadius(); }
    float top()         { return y() - shape.getRadius(); }
    float bottom ()     { return y() + shape.getRadius(); }
};

class Paddle {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Paddle(float x, float y) 
    {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(paddle_width, paddle_height));
        shape.setFillColor(paddle_color);
        shape.setOrigin(paddle_width / 2, paddle_height / 2 );
    }

    void setX(float x)
    {
        shape.setPosition(x, shape.getPosition().y);
    }

    float x()           { return shape.getPosition().x; }
    float y()           { return shape.getPosition().y; }
    float left()        { return x() - shape.getSize().x / 2.f; }
    float right()       { return x() + shape.getSize().x / 2.f; }
    float top()         { return y() - shape.getSize().y / 2.f; }
    float bottom ()     { return y() + shape.getSize().y / 2.f; }
};

class Brick 
{
public:
    sf::RectangleShape shape;

    bool destroyed;

    Brick(float x, float y) 
    {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(block_width, block_height));
        shape.setFillColor(brick_color);
        shape.setOrigin(block_width /2.f, block_height /2.f );
        destroyed = false;
    }

    float x()           { return shape.getPosition().x; }
    float y()           { return shape.getPosition().y; }
    float left()        { return x() - shape.getSize().x / 2.f; }
    float right()       { return x() + shape.getSize().x / 2.f; }
    float top()         { return y() - shape.getSize().y / 2.f; }
    float bottom ()     { return y() + shape.getSize().y / 2.f; }
};

template <class T1, class T2> 
bool isIntersecing (T1& mA, T2& mB) 
{
    return  mA.right()  >= mB.left()   && 
            mA.left()   <= mB.right()  && 
            mA.bottom() >= mB.top()    && 
            mA.top()    <= mB.bottom();
}

void testCollision(Paddle& mPaddle, Ball& mBall) 
{
    if (!isIntersecing(mPaddle, mBall)) return;

    // Следующие строки определяют угол отражения шарика от ракетки при столкновении
    mBall.velocity.x  = 2.0f*ball_velocity * (mBall.x() - mPaddle.x()) / (mBall.shape.getRadius() + mPaddle.shape.getSize().x);
    if (ball_velocity*ball_velocity - mBall.velocity.x*mBall.velocity.x <= 0)
    {
        mBall.velocity.x = ball_velocity*ball_velocity/mBall.velocity.x;
    }
    mBall.velocity.y = -sqrt(ball_velocity*ball_velocity - mBall.velocity.x*mBall.velocity.x);
}

void testCollision(Brick& mBrick, Ball& mBall) 
{

    if(!isIntersecing(mBrick, mBall) || mBrick.destroyed) return;

    mBrick.destroyed = true;

    float overlapLeft = mBall.right() - mBrick.left();
    float overlapRight = mBrick.right() - mBall.left();
    float overlapTop = mBrick.bottom() - mBall.top();
    float overlapBottom = mBrick.top() - mBall.bottom();

    bool ballFromLeft = std::fabs(overlapLeft) < std::fabs(overlapRight);
    bool ballFromTop = std::fabs(overlapTop) < std::fabs(overlapBottom);

    float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
    float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

    if(std::fabs(minOverlapX) < std::fabs(minOverlapY))
        mBall.velocity.x *= -1;
    else
        mBall.velocity.y *= -1;
}