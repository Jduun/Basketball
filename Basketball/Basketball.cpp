#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Ball.h"

int main()
{
	/*
	const int HEIGHT = 600;
	const int WIDTH = 1120;
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Basketball");
	window->setFramerateLimit(60);
	Ball ball(WIDTH / 2 - 5, HEIGHT / 2 - 5, sf::Color(180, 50, 0), 5);
	while (window->isOpen())
	{
		sf::Event e;
		while (window->pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				window->close();
			}
		}
		window->clear(sf::Color(255, 160, 122));
		if (ball.Pass(200, 400))
		{

		}
		ball.Update(window);
		ball.Draw(window);
		window->display();
	}
	delete window;
	*/
	Game* game = new Game();
	game->Play();
	delete game;
	return 0;
}