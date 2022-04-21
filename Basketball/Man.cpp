#include "Man.h"

Man::Man(double x, double y, sf::Color color, double size) : Object(x, y, color), size(size), ball(nullptr) {}

void Man::Draw(sf::RenderWindow* window)
{
	sf::CircleShape shape(size);
	shape.setPosition(x, y);
	shape.setFillColor(color);
	window->draw(shape);
	if (ball != nullptr)
	{
		ball->setPosition(this->x, this->y);
		ball->Draw(window);
	}
}

void Man::Update(sf::RenderWindow* window)
{
	x += rand() % 3 - 1;
	y += rand() % 3 - 1;
	x = fmin(fmax(0, x), window->getSize().x);
	y = fmin(fmax(0, y), window->getSize().y);
}

void Man::setBall(Ball* _ball)
{
	ball = _ball;
}

Ball* Man::getBall()
{
	return ball;
}