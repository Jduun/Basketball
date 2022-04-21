#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Ball.h"

int main()
{
	Game* game = new Game();
	game->Play();
	delete game;
	return 0;
}