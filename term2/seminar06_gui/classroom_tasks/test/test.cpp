#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;

struct Rectangle
{
	sf::Vector2i position;
	int width, height;
	sf::Color color;
};

struct Description
{
    sf::Vector2f position;
    std::string text;
};

class Slider 
{
private:
	static const sf::Color default_color;
    static const sf::Color hover_color;
    static const sf::Color pressed_color;
    static const sf::Color base_color;

    Rectangle base, slider;

    sf::Font& font;

    sf::Text text;
    sf::RectangleShape shape;

    int slider_min_position;
    int slider_max_position;
    sf::Vector2i mouse_position;

    int slider_position;
    
    bool is_taken = false;
public:
	Slider (int x, int y, int width, int height, sf::Font& font) : font(font)
	{
        base.width = width;
        base.height = height / 5;
        slider.width = base.height * 1.5;
        slider.height = height;

        text.setFont(font);
        text.setCharacterSize(base.height * 2);
        text.setFillColor(sf::Color::White);
        text.setOrigin(0, text.getCharacterSize() / 2);
        text.setPosition((float)(x + width), (float)y);
        sf::FloatRect text_size = text.getLocalBounds();

        slider_min_position = x + slider.width * 0.2;
        slider_max_position = x + width - slider.width * 1.2;

        base.position = {x, y};
        slider.position = {slider_min_position, y - (slider.height - base.height) / 2};

        text.setPosition(x + width + 5, y);

        base.color = base_color;
        slider.color = default_color;

        slider_position = 0;

        bool is_taken = false;
	}

	void draw(sf::RenderWindow& window)
	{
		shape.setPosition((sf::Vector2f)base.position);
		shape.setFillColor(base.color);
		shape.setSize(sf::Vector2f(base.width, base.height));
		window.draw(shape);

		shape.setPosition((sf::Vector2f)slider.position);
		shape.setFillColor(slider.color);
		shape.setSize(sf::Vector2f(slider.width, slider.height));
		window.draw(shape);

		slider_position = 100 * (slider.position.x - slider_min_position) / (slider_max_position - slider_min_position);
		text.setString(std::to_string(slider_position));
		window.draw(text);

	}

	const int getValue()
    {
        return slider_position;
    }

    bool checkCollision(int x, int y)
    {
        return (x > slider.position.x && 
                x < slider.position.x + slider.width &&
                y > slider.position.y &&
                y < slider.position.y + slider.height);
    }

    bool checkBaseCollision (int x, int y)
    {
    	return (x > base.position.x && 
                x < base.position.x + base.width &&
                y > slider.position.y &&
                y < slider.position.y + slider.height);
    }
    

    void onMouseHover(sf::Event& event)
    {
        if (is_taken)
            return;
        if (checkCollision(event.mouseMove.x, event.mouseMove.y))
            slider.color = hover_color;
        else
            slider.color = default_color;
    }

    void onMousePressed(sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
        	mouse_position = {event.mouseButton.x, event.mouseButton.y};
        	
//if user clicks on the base
        	if (checkBaseCollision(event.mouseButton.x, event.mouseButton.y) && !is_taken)
            {
            	slider.position.x = mouse_position.x - slider.width / 2;
            	if (slider.position.x >= slider_max_position)
    				slider.position.x = base.position.x + base.width - slider.width * 1.2;
    			if (slider.position.x < slider_min_position)
    				slider.position.x = base.position.x + slider.width * 0.2;

            }
            if (checkCollision(event.mouseButton.x, event.mouseButton.y))
            {
                is_taken = true;
                slider.color = pressed_color;
            }
            
            
        }
    }

    void onMouseMoved (sf::Event& event)
    {
    	mouse_position = {event.mouseMove.x, event.mouseMove.y};
    	if (is_taken)
    	{
    		if (mouse_position.x >= slider_min_position + 0.5 * slider.width && mouse_position.x <= slider_max_position + 0.5 * slider.width)
    			slider.position.x = mouse_position.x - 0.5 * slider.width;

// if mouse moves too fast
    		if (slider.position.x != slider_min_position && slider.position.x != slider_max_position)
    		{
    			if (mouse_position.x >= slider_max_position + slider.width)
    				slider.position.x = slider_max_position;
    			if (mouse_position.x <= slider_min_position)
    				slider.position.x = slider_min_position;
    		}
    		
    	}
    }

    void onMouseReleased(sf::Event& event)
    {
        if (checkCollision(event.mouseButton.x, event.mouseButton.y))
            slider.color = hover_color;
        else
            slider.color = default_color;
        is_taken = false;
    }
};

const sf::Color Slider::default_color = sf::Color(100, 100, 100);
const sf::Color Slider::hover_color = sf::Color(125, 125, 125);
const sf::Color Slider::pressed_color = sf::Color(170, 170, 170);
const sf::Color Slider::base_color = sf::Color(105, 105, 105);

int main ()
{
	sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 650), "Slider", sf::Style::Close, settings);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("consolas.ttf"))
    {
        cout << "Can't load button font" << endl;
    }

    float radius = 50;
    sf::CircleShape circle (radius);
    circle.setFillColor(sf::Color::White);
    circle.setPosition({400, 200});
    circle.setOrigin(circle.getRadius(), circle.getRadius());

    sf::Text text;
    text.setCharacterSize(30);
    text.setFont(font);
    text.setFillColor(sf::Color::White);
    text.setPosition(100, 400);
    text.setOrigin(0, text.getCharacterSize() / 2);
    std::vector<Description> descriptions = {
        {{100, 400}, "Color:"},
        {{500, 400}, "Radius:"},
        {{70, 450}, "R"},
        {{70, 510}, "G"},
        {{70, 570}, "B"}
    };
    

    std::vector<Slider> sliders = {
        {100, 450, 100, 50, font},
        {100, 510, 300, 10, font},
        {100, 570, 400, 40, font},
        {500, 450, 200, 80, font}
    };
    Slider slid(150, 100, 500, 100, font);

    while(window.isOpen())
    {
    	sf::Event event;
    	while (window.pollEvent(event))
    	{
    		if (event.type == sf::Event::Closed)
                window.close();

        	if (event.type == sf::Event::MouseMoved)
        	{
                for (Slider& s : sliders)
                {
        		  s.onMouseHover(event);
        		  s.onMouseMoved(event);
                }
    	    }

        	if (event.type == sf::Event::MouseButtonPressed)
        	{
                for (Slider& s : sliders)
                    s.onMousePressed(event);
        		
        	}

        	if (event.type == sf::Event::MouseButtonReleased)
        	{
                for (Slider& s : sliders)
                    s.onMouseReleased(event);
        		
        	}
    	}

        circle.setRadius(radius + sliders[3].getValue());
        circle.setOrigin({circle.getRadius(), circle.getRadius()});
        circle.setFillColor({sliders[0].getValue() * 2.5, sliders[1].getValue() * 2.5, sliders[2].getValue() * 2.5});


        window.clear({15, 15, 15});
        for (Slider& s : sliders)
            s.draw(window);
        window.draw(circle);

        for (Description& d : descriptions)
        {   
            text.setPosition(d.position);
            text.setString(d.text);
            window.draw(text);
        }
        //window.draw(text);
        window.display();

    }
}