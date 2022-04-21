#pragma once
#include "Object.h"
#include "Ball.h"
#include "Man.h"
#include "Basket.h"
#include <vector>
#include "Object.h"
#include <random>
#include <ctime>
#include <iostream>
#include <vector>

class Game
{
public:
	Game();
	~Game();
	void Draw();
	void Play();

private:
	const int HEIGHT = 600;
	const int WIDTH = 1120;
	const int COUNT_MEMBERS = 5;
	sf::RenderWindow* window;
	std::vector<Object*> objects;
};
