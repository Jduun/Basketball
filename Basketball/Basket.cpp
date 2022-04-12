#include "Basket.h"

Basket::Basket(double x, double y, sf::Color color, double radius, double thickness) :
	Object(x, y, color), radius(radius), thickness(thickness) {}

void Basket::Draw(sf::RenderWindow* window)
{
	sf::CircleShape shape(radius);
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color(0, 0, 0, 0)); // внутренность делаем прозрачной
	shape.setOutlineThickness(thickness);
	shape.setOutlineColor(color);
	window->draw(shape);
}

void Basket::Update(sf::RenderWindow* window)
{

}