#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


// Класс флажка
class Checkbox
{
private:
    // Статические константы, общие для всех флажков
    inline static const int boundarySize = 24;
    inline static const int outerSize = 16;
    inline static const int innerSize = 10;

    inline static const sf::Color outerColor {sf::Color::White};
    inline static const sf::Color innerColor {sf::Color::Black};
    inline static const sf::Color textColor {sf::Color::White};


    // Внешний квадратик
    sf::RectangleShape outerShape;
    // Внутрений квадратик
    sf::RectangleShape innerShape;
    sf::Font& font;
    sf::Text text;

    bool isActivated;

public:
    Checkbox(int x, int y, sf::Font& font, const sf::String& textData) : font(font)
    {
        text.setFont(font);
        text.setString(textData);
        text.setCharacterSize(24);
        text.setFillColor(textColor);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setPosition(x + boundarySize, y + boundarySize/2 - textRect.height);

        outerShape.setPosition(x + boundarySize/2 - outerSize/2, y + boundarySize/2 - outerSize/2);
        outerShape.setSize(sf::Vector2f(outerSize, outerSize));
        outerShape.setFillColor(outerColor);

        innerShape.setPosition(x + boundarySize/2 - innerSize/2, y + boundarySize/2 - innerSize/2);
        innerShape.setSize(sf::Vector2f(innerSize, innerSize));
        innerShape.setFillColor(innerColor);

        isActivated = false;
        text.setFont(font);
    }

    bool getIsActivated() const
    {
        return isActivated;
    }

    std::string getTitle() const
    {
        return text.getString();
    }

    void draw(sf::RenderWindow& window) const
    {
        window.draw(text);
        window.draw(outerShape);
        if (isActivated) {
            window.draw(innerShape);
        }
    }

    bool checkCollision(int x, int y)
    {
        return (x > outerShape.getPosition().x && 
                x < outerShape.getPosition().x + outerShape.getSize().x &&
                y > outerShape.getPosition().y &&
                y < outerShape.getPosition().y + outerShape.getSize().y);
    }

    void onMousePressed(const sf::Event& event, const sf::RenderWindow& window)
    {
        sf::Vector2f worldPos = window.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (checkCollision(worldPos.x, worldPos.y)) {
                isActivated = !isActivated;
            }
        }
    }
};










int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Checkbox Class!");
    window.setFramerateLimit(20);

    // Это для надписи вверху слева:
    sf::Font consolas_font;
    if (!consolas_font.loadFromFile("consolas.ttf")) {
        std::cout << "Can't load button font consolas.txt" << std::endl;
    }
    sf::Text info;
    info.setFont(consolas_font);
    info.setString("Checkboxes activated: ");
    info.setCharacterSize(22);


    std::vector<Checkbox> checkboxes = { 
        {400, 100, consolas_font, "Moscow"},
        {400, 150, consolas_font, "New York"},
        {400, 200, consolas_font, "Paris"},
        {400, 250, consolas_font, "Lagos"},
        {400, 300, consolas_font, "Tokyo"},
        {400, 350, consolas_font, "Lima"}
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                for (auto& cb : checkboxes) {
                    cb.onMousePressed(event, window);
                }

                sf::String infoString = "Checkboxes activated: ";
                for (const auto& cb : checkboxes) {
                    if (cb.getIsActivated()) {
                        infoString += cb.getTitle() + ", ";
                    }
                    info.setString(infoString);
                }
            }

        }

        window.clear(sf::Color::Black);
        for (const auto& cb : checkboxes) {
            cb.draw(window);
        }

        window.draw(info);
        window.display();
    }

    return 0;
}