#pragma once
#include "Object.h"
#include "Ball.h"
#include "Man.h"

#include <vector>

class Game
{
public:
	Game();
	~Game();
	void Draw();

private:
	const int HEIGHT = 600;
	const int WIDTH = 1120;
	const int COUNT_MEMBERS = 5;
	sf::RenderWindow* window;
	std::vector<Object*> objects;
};
