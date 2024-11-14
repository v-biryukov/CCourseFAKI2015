#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// Класс кнопки
class Button
{
private:
    // Статические поля класса, это поля общие для всех экземпляров класса
    inline static const sf::Color kDefaultColor {220, 220, 220};
    inline static const sf::Color kHoverColor   {180, 200, 180};
    inline static const sf::Color kPressedColor {140, 160, 140};
    inline static sf::RectangleShape sShape {};


    // Храним указатель на окно SFML, на которое будем отрисовывать кнопку
    sf::RenderWindow* mpSFMLWindow;

    // Текст, границы прямоугольника и текущий цвет кнопки
    sf::Text mText;
    sf::FloatRect mRect;
    sf::Color mCurrentColor;
    
    // Когда кнопка находится в нажатом состоянии, 
    // то mIsPressed = true (Пользователь зажал кнопку и держит)
    bool mIsPressed;

public:

    Button(sf::RenderWindow* pWindow, sf::FloatRect mRect, sf::Font& font, int fontSize, const sf::String& mTextData) 
            : mpSFMLWindow(pWindow), mRect(mRect)
    {
        mText.setFont(font);
        mText.setString(mTextData);
        mText.setCharacterSize(fontSize);
        mText.setFillColor(sf::Color::Black);
        sf::FloatRect mTextRect = mText.getLocalBounds();

        mText.setPosition(mRect.left + (mRect.width - mTextRect.width) / 2, 
                         mRect.top  + (mRect.height - mTextRect.height) / 2);

        mCurrentColor = kDefaultColor;
        mIsPressed = false;
        mIsActivated = false;
    }

    // Метод, который рисует кнопку на холсте окна *mpSFMLWindow
    void draw()
    {
        sShape.setPosition({mRect.left, mRect.top});
        sShape.setSize({mRect.width, mRect.height});
        sShape.setFillColor(mCurrentColor);
        mpSFMLWindow->draw(sShape);
        mpSFMLWindow->draw(mText);
    }

    // Метод, который срабатывает каждый раз, когда двигается мышь
    void onMouseMove(const sf::Event& event)
    {
        if (mIsPressed) {
            return;
        }
        sf::Vector2f mouseCoords = mpSFMLWindow->mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        if (mRect.contains(mouseCoords)) {
            mCurrentColor = kHoverColor;
        }
        else {
            mCurrentColor = kDefaultColor;
        }
    }

    // Метод, который срабатывает каждый раз, когда нажимется кнопка мыши
    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mouseCoords = mpSFMLWindow->mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mRect.contains(mouseCoords)) {
                mIsPressed = true;
                mCurrentColor = kPressedColor;
            }
        }
    }

    // Метод, который срабатывает каждый раз, когда отпускается кнопка мыши
    // Возвращает true, если нажатие на кнопку произошло
    bool onMouseReleased(const sf::Event& event)
    { 
        if (!mIsPressed) {
            return false;
        }
        mIsPressed = false;

        sf::Vector2f mouseCoords = mpSFMLWindow->mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        if (mRect.contains(mouseCoords)) {
            mCurrentColor = kHoverColor;
            return true;
        }
        else {
            mCurrentColor = kDefaultColor;
            return false;
        }
    }

    // Нужно вызвать лишь этот метод в цикле обработки событий
    bool handleEvent(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseMoved) {
            onMouseMove(event);
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            onMousePressed(event);
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            return onMouseReleased(event);
        }
        return false;
    }
};