#pragma once

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "vector"
using namespace sf;

class GameCore
{
	RenderWindow* window;
	std::vector <Circle*> circles;

	void update(int elapsed);
	void draw();

public:
	GameCore(int w, int h);
	GameCore();
	void start();
	~GameCore();
};


