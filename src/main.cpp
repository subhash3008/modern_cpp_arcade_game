#include <iostream>
#include <SFML/Graphics.hpp>

#include <string>
#include "../include/constants.h"
#include "../include/creature.h"

using namespace std;
using namespace std::literals;

int main()
{
	std::cout << "Hello\r\n" << std::endl;

	// instantiate the creature
	Creature the_creature(constants::window_width / 2.0, constants::window_height / 2.0);

	// Create game window using SFML RenderWindow
	sf::RenderWindow game_window{
		{constants::window_width, constants::window_height},
		"Simple Breakout Game"s
	};

	// Limit the render window frame rate
	game_window.setFramerateLimit(60);

	while (game_window.isOpen())
	{
		// clear the screen
		game_window.clear(sf::Color::Red);

		// Check for any event since last loop iteration
		sf::Event event;

		// if the user pressed "Escape" or clicked on
		// "Close", close the window and terminate the
		// program
		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				game_window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			game_window.close();
		}

		// calcualate the updated state of game
		the_creature.update();

		// display the updated state of the game
		the_creature.draw(game_window);
		game_window.display();
	}

	return 0;
}