#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "world.h"

int main () 
{
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Player states");
	window.setFramerateLimit(60);

	float time = 0;
	float dt = 1.0 / 60;

	World world;
	world.add_block({-500, 770, 2000, 400});
	world.add_block({-400, 100, 700, 300});

	world.add_block({600, 500, 300, 120});
	world.add_block({800, 0, 400, 200});

	world.add_block({-100, -730, 400, 100});
	world.add_block({700, -730, 400, 100});
	world.add_block({1500, -730, 400, 100});
	world.add_block({1100, -300, 400, 100});

	while (window.isOpen()) 
	{
		sf::Event event;
		while(window.pollEvent(event)) 
		{
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
			{
				window.close();
			}
			world.handle_events(event);
		}
		window.clear(sf::Color::Black);
		world.update(dt);
		world.draw(window);

		window.display();

		time += 1.0 / 60;
	}

	return EXIT_SUCCESS;
}