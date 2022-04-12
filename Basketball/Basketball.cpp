#include <SFML/Graphics.hpp>
#include "Basket.h"
#include "Man.h"
#include "Ball.h"
#include <vector>
#include "Object.h"
#include <random>
#include <ctime>
#include <iostream>

int main()
{
	const int HEIGHT = 600;
	const int WIDTH = 1120;
	const int COUNT_MEMBERS = 5;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Basketball");
	window.setFramerateLimit(60);
	std::vector<Object*> objects
	{
		new Basket(20, HEIGHT / 2 - 20, sf::Color(100, 0, 0), 20, 5),
		new Basket(WIDTH - 20 * 2 - 20, HEIGHT / 2 - 20, sf::Color(100, 0, 0), 20, 5),
		new Ball(WIDTH / 2 - 5, HEIGHT / 2 - 5, sf::Color(180, 50, 0), 5)
	};
	srand(time(nullptr));
	std::vector<Man*> greenMans;
	std::vector<Man*> blueMans;
	for (int i = 0; i < COUNT_MEMBERS; i++)
	{
		greenMans.push_back(new Man(rand() % WIDTH, rand() % HEIGHT, sf::Color(0, 100, 0), 10));
		blueMans.push_back(new Man(rand() % WIDTH, rand() % HEIGHT, sf::Color(0, 0, 100), 10));
		objects.push_back(greenMans[i]);
		objects.push_back(blueMans[i]);
	}
	for (int i = 0; i < COUNT_MEMBERS; i++)
	{
		for (int j = i + 1; j < COUNT_MEMBERS; j++)
		{
			if (greenMans[j]->getX() < greenMans[i]->getX())
			{
				Man* temp = greenMans[i];
				greenMans[i] = greenMans[j];
				greenMans[j] = temp;
			}
		}
	}
	greenMans[0]->setBall((Ball*)objects[2]);
	int count = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color(255, 160, 122));
		if (count < COUNT_MEMBERS - 1)
		{
			if (greenMans[count]->Pass(greenMans[count + 1], (Ball*)objects[2]))
			{
				count++;
			}
		}
		if (count == COUNT_MEMBERS - 1)
		{
			greenMans[COUNT_MEMBERS - 1]->Pass(WIDTH - 20 * 2 - 20 + 15, HEIGHT / 2 - 20 + 15, (Ball*)objects[2]);
		}
		for (auto object : objects)
		{
			object->Draw(&window);
			object->Update(&window);
		}
		window.display();
	}
	return 0;
}