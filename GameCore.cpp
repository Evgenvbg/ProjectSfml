#include "GameCore.h"
using namespace sf;

void GameCore::update(int elapsed)
{
	
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();

			if (event.type == Event::MouseButtonPressed &&
				event.mouseButton.button == Mouse::Right) {				
				circles.push_back(new Circle(event.mouseButton.x , event.mouseButton.y));
						
			}
			if (event.type == Event::MouseButtonPressed &&
				event.mouseButton.button == Mouse::Left) {
				for (auto circle : circles) {
					if (circle->isPointInside(Vector2f(event.mouseButton.x, event.mouseButton.y))) {
						circle->select();
					}
					else {
						circle->deselect();
					}
				}
			}
		}
}

void GameCore::draw()
{
	window->clear();
	for (auto circle : circles) {
		circle->draw(window);
	}
	
	window->display();
}

GameCore::GameCore(int w, int h)
{
	window = new RenderWindow(VideoMode(w, h), "sfml");
	//circles = new Circle();
}

GameCore::GameCore() : GameCore (600 , 600)
{

}

void GameCore::start(){
	Clock clc;

	while (window->isOpen())
	{
		int elapsed = clc.restart().asMicroseconds();
		update(elapsed);
		draw();

	}
}

GameCore::~GameCore()
{
	delete window;
}
