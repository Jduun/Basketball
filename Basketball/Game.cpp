#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Basketball");

}

Game::~Game()
{
	delete window;
}

void Game::Draw()
{

}