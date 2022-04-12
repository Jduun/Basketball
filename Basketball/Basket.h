#pragma once
#include "Object.h"

class Basket : public Object
{
public:
	Basket(double x, double y, sf::Color color, double radius, double thickness);
	void Draw(sf::RenderWindow* window) override;
	void Update(sf::RenderWindow* window) override;

private:
	double radius;
	double thickness;
};
