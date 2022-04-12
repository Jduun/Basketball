#include "Object.h"

Object::Object(double x, double y, sf::Color color) : x(x), y(y), color(color) {}


double Object::getX()
{
	return x;
}

double Object::getY()
{
	return y;
}

void Object::setX(double _x)
{
	x = _x;
}

void Object::setY(double _y)
{
	y = _y;
}