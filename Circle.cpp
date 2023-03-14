#include "Circle.h"

Circle::Circle(int w, int h)
{
	circ = new CircleShape(100);
	circ->setPosition(w, h);
	circ->setOrigin(100, 100);

	deselect();
}

Circle::Circle() : Circle(200, 200)
{

}

void Circle::select()
{
	selected = true;
	circ->setFillColor(Color::Red);
}

void Circle::deselect()
{
	selected = false;
	circ->setFillColor(Color::Magenta);
}

bool Circle::isSelect()
{
	return selected;
}

void Circle::draw(RenderWindow* window)
{
	window->draw(*circ);
}

bool Circle::isPointInside(Vector2f point)
{
	auto circlePos = circ->getPosition();
	return  ((circlePos.x - point.x) * (circlePos.x - point.x) + (circlePos.y - point.y) * (circlePos.y - point.y)
		< circ->getRadius() * circ->getRadius());
	
	
}
