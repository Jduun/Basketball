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

bool Ball::Pass(double _x, double _y)
{
	if (pow(x - _x, 2) + pow(y - _y, 2) <= 100)
	{
		return true;
	}
	const double V = 10;
	double vx = _x - x;
	double vy = _y - y;
	double vLength = pow(vx * vx + vy * vy, 0.5);
	vx *= V;
	vy *= V;
	vx /= vLength;
	vy /= vLength;
	x += vx;
	y += vy;
	return false;
}