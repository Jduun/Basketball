#include "Ball.h"

Ball::Ball(double x, double y, sf::Color color, double radius) : Object(x, y, color), radius(radius) {}

void Ball::Draw(sf::RenderWindow* window)
{
	sf::CircleShape shape(radius);
	shape.setPosition(x, y);
	shape.setFillColor(color);
	window->draw(shape);
}

void Ball::Update(sf::RenderWindow* window)
{

}

void Ball::setPosition(double _x, double _y)
{
	x = _x;
	y = _y;
}