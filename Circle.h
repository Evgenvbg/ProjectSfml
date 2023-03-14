#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Circle
{
	CircleShape* circ;
	bool selected;

public:

	Circle(int w, int h);
	Circle();
	void select();
	void deselect();
	bool isSelect();
	void draw(RenderWindow* window);
	bool isPointInside(Vector2f point);

};

