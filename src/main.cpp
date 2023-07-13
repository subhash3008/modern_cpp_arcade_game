#include <iostream>
#include <SFML/Graphics.hpp>

#include <string>
#include "../include/constants.h"
// #include "../include/creature.h"
#include "../include/background.h"
#include "../include/ball.h"
#include "../include/paddle.h"

using namespace std;
using namespace std::literals;

int main()
{
	std::cout << "Hello\r\n" << std::endl;

	// instantiate the creature
	// Creature the_creature(constants::window_width / 2.0, constants::window_height / 2.0);

	// Create the background object
	Background the_bg(0.0f, 0.0f);

	// create the ball
	Ball the_ball(
		constants::window_width / 2.0f,
		constants::window_height / 2.0f
	);

	// Create the paddle
	Paddle the_paddle(
		constants::window_width / 2.0f,
		constants::window_height - constants::paddle_height * 2
	);

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
		game_window.clear(sf::Color::Black);

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
		// the_creature.update();
		the_bg.update();
		the_ball.update();
		the_paddle.update();

		// display the updated state of the game
		// the_creature.draw(game_window);
		the_bg.draw(game_window);
		the_ball.draw(game_window);
		the_paddle.draw(game_window);
		
		game_window.display();
	}

	return 0;
}