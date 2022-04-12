#pragma once
#include <SFML/Graphics.hpp>

class Object
{
public:
	Object(double x, double y, sf::Color color);
	virtual void Draw(sf::RenderWindow* window) = 0;
	virtual void Update(sf::RenderWindow* window) = 0;
	double getX();
	double getY();
	void setX(double _x);
	void setY(double _y);

protected:
	double x;
	double y;
	sf::Color color;
};