#include "Man.h"

Man::Man(double x, double y, sf::Color color, double size) : Object(x, y, color), size(size) {}

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
	x += rand() % 11 - 5;
	y += rand() % 11 - 5;
	x = (x < 0 ? 0 : x);
	y = (y < 0 ? 0 : y);
	x = (x > window->getSize().x ? window->getSize().x : x);
	y = (y > window->getSize().y ? window->getSize().y : y);
}

void Man::setBall(Ball* _ball)
{
	ball = _ball;
}

void Man::Pass(double _x, double _y, Ball* _ball)
{
	if (pow(_ball->getX() - _x, 2) + pow(_ball->getY() - _y, 2) <= 300)
	{
		return;
	}
	if (ball != nullptr)
	{
		_ball->setX(this->getX());
		_ball->setY(this->getY());
	}
	this->setBall(nullptr);
	const double V = 3;
	double vx = _x - x;
	double vy = _y - y;
	double vLength = pow(vx * vx + vy * vy, 0.5);
	vx /= vLength;
	vy /= vLength;
	vx *= V;
	vy *= V;
	_ball->setX(_ball->getX() + vx);
	_ball->setY(_ball->getY() + vy);
}

bool Man::Pass(Man* man, Ball* _ball)
{
	if (pow(_ball->getX() - man->getX(), 2) + pow(_ball->getY() - man->getY(), 2) <= 100)
	{
		man->setBall(_ball);
		return true;
	}
	if (ball != nullptr)
	{
		_ball->setX(this->getX());
		_ball->setY(this->getY());
	}
	this->setBall(nullptr);
	const double V = 10;
	double vx = man->getX() - _ball->getX();
	double vy = man->getY() - _ball->getY();
	double vLength = pow(vx * vx + vy * vy, 0.5);
	vx /= vLength;
	vy /= vLength;
	vx *= V;
	vy *= V;
	_ball->setX(_ball->getX() + vx);
	_ball->setY(_ball->getY() + vy);
	
	return false;
}

Ball* Man::getBall()
{
	return ball;
}