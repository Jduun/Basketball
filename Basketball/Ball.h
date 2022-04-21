#pragma once
#include "Object.h"

class Ball : public Object
{
public:
	Ball(double x, double y, sf::Color color, double radius);
	void Draw(sf::RenderWindow* window) override;
	void Update(sf::RenderWindow* window) override;
	void setPosition(double _x, double _y);
	bool Pass(double _x, double _y);

private:
	double radius;
};
