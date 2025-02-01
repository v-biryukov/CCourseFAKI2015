#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Draggable
{
private:

    sf::RectangleShape mShape   {};
    bool mIsDragged             {false};
    sf::Vector2f mOffset        {0.0f, 0.0f};

public:
    Draggable() {};
    Draggable(const sf::RectangleShape& shape) : mShape{shape} {}
    Draggable(sf::Vector2f position, sf::Vector2f size, sf::Color color) 
    {
        mShape.setPosition(position);
        mShape.setSize(size);
        mShape.setFillColor(color);
    }

    bool onMousePressed(sf::Vector2f mousePosition)
    {
        if (mShape.getGlobalBounds().contains(mousePosition))
        {
            mIsDragged = true;
            mOffset = mousePosition - mShape.getPosition();
        }
        return mIsDragged;
    }

    void onMouseReleased()
    {
        mIsDragged = false;
    }

    void onMouseMoved(sf::Vector2f mousePosition)
    {
        if (mIsDragged)
        {
            mShape.setPosition(mousePosition - mOffset);
        }
    }

    void setColor(sf::Color c)
    {
        mShape.setFillColor(c);
    }

    void setSize(sf::Vector2f sz)
    {
        mShape.setSize(sz);
    }

    void setPosition(sf::Vector2f p)
    {
        mShape.setPosition(p);
    }

    sf::Vector2f getPosition() const
    {
        return mShape.getPosition();
    }

    bool isDragged() const
    {
        return mIsDragged;
    }

    void draw(sf::RenderWindow& rw) const
    {
        rw.draw(mShape);
    }
};



class BaseWindow
{
private:

    sf::RectangleShape mBaseRect {};
    Draggable mDragRect {};

    sf::Vector2f mOffset;

public:

    BaseWindow(const sf::RectangleShape& baseRect, const Draggable& dragRect) 
        : mBaseRect(baseRect),  mDragRect(dragRect)
    {
        mOffset = mDragRect.getPosition() - mBaseRect.getPosition();
    }


    bool onMousePressed(sf::Vector2f mousePosition)
    {
        return mDragRect.onMousePressed(mousePosition);
    }

    void onMouseReleased()
    {
        mDragRect.onMouseReleased();
    }

    void onMouseMoved(sf::Vector2f mousePosition)
    {
        mDragRect.onMouseMoved(mousePosition);

        if (mDragRect.isDragged())
            mBaseRect.setPosition(mDragRect.getPosition() - mOffset);
    }

    void setBaseColor(sf::Color c)
    {
        mBaseRect.setFillColor(c);
    }

    void setBaseSize(sf::Vector2f sz)
    {
        mBaseRect.setSize(sz);
    }

    void setDragColor(sf::Color c)
    {
        mDragRect.setColor(c);
    }

    void setDragSize(sf::Vector2f sz)
    {
        mDragRect.setSize(sz);
    }

    void setPosition(sf::Vector2f p)
    {
        mBaseRect.setPosition(p);
        mDragRect.setPosition(mBaseRect.getPosition() + mOffset);
    }

    void draw(sf::RenderWindow& rw) const
    {
        rw.draw(mBaseRect);
        mDragRect.draw(rw);
    }
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Windows");
    window.setFramerateLimit(60);

    sf::RectangleShape rs;
    rs.setPosition({100, 100});
    rs.setSize({300, 300});
    rs.setFillColor({100, 50, 90});

    Draggable d;
    d.setPosition({120, 250});
    d.setSize({200, 20});
    d.setColor({200, 200, 150});

    BaseWindow b1(rs, d);


    rs.setPosition({300, 300});
    rs.setSize({300, 200});
    rs.setFillColor({240, 240, 240});

    d.setPosition({300, 300});
    d.setSize({300, 30});
    d.setColor({150, 150, 150});

    BaseWindow b2(rs, d);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                b1.onMousePressed(mousePosition);
                b2.onMousePressed(mousePosition);
            }

            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
                b1.onMouseReleased();
                b2.onMouseReleased();
            }

            if (event.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
                b1.onMouseMoved(mousePosition);
                b2.onMouseMoved(mousePosition);
                
            }
        }
        
        window.clear(sf::Color::Black);
        b1.draw(window);
        b2.draw(window);
        window.display();
    }
}