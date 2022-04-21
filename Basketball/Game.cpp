#include "Game.h"

Game::Game()
{
	srand(time(nullptr));
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Basketball");
	window->setFramerateLimit(60);
	objects.push_back(new Basket(20, HEIGHT / 2 - 20, sf::Color(100, 0, 0), 20, 5));
	objects.push_back(new Basket(WIDTH - 20 * 2 - 20, HEIGHT / 2 - 20, sf::Color(100, 0, 0), 20, 5));
	objects.push_back(new Ball(WIDTH / 2 - 5, HEIGHT / 2 - 5, sf::Color(180, 50, 0), 5));
	for (int i = 0; i < COUNT_MEMBERS; i++)
	{
		objects.push_back(new Man(rand() % WIDTH, rand() % HEIGHT, sf::Color(0, 100, 0), 10));
	}
	for (int i = 0; i < COUNT_MEMBERS; i++)
	{
		objects.push_back(new Man(rand() % WIDTH, rand() % HEIGHT, sf::Color(0, 0, 100), 10));
	}
	Man* man = dynamic_cast<Man*>(objects[3]);
	Ball* ball = dynamic_cast<Ball*>(objects[2]);
	if (man && ball)
	{
		man->setBall(ball);
	}
}

Game::~Game()
{
	delete window;
}

void Game::Draw()
{

}

void Game::Play()
{
	int count = 0;
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
		if (count < COUNT_MEMBERS - 1)
		{
			Ball* ball = dynamic_cast<Ball*>(objects[2]);
			Man* man1 = dynamic_cast<Man*>(objects[3 + count]);
			Man* man2 = dynamic_cast<Man*>(objects[3 + count + 1]);
			if (man1 && man1->getBall())
			{
				man1->setBall(nullptr);
			}
			if (ball && man2 && ball->Pass(man2->getX(), man2->getY()))
			{
				man2->setBall(ball);
				count++;
			}
		}
		if (count == COUNT_MEMBERS - 1)
		{
			Ball* ball = dynamic_cast<Ball*>(objects[2]);
			Man* man = dynamic_cast<Man*>(objects[3 + COUNT_MEMBERS - 1]);
			if (man && ball)
			{
				man->setBall(nullptr);
			}
			if (ball)
			{
				ball->Pass(WIDTH - 20 * 2, HEIGHT / 2);
			}
		}
		for (auto object : objects)
		{
			object->Draw(window);
			object->Update(window);
		}
		window->display();
	}
}