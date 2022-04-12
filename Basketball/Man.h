#pragma once
#include "Object.h"
#include "Ball.h"
#include <random>
#include <ctime>

class Man : public Object
{
public:
	Man(double x, double y, sf::Color color, double size);
	void Draw(sf::RenderWindow* window) override;
	void Update(sf::RenderWindow* window) override;
	void setBall(Ball* _ball);
	void Pass(double _x, double _y, Ball* _ball);
	bool Pass(Man* man, Ball* _ball);
	Ball* getBall();
	
private:
	double size;
	Ball* ball;
};