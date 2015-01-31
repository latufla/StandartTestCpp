// SQTest.cpp : Defines the entry point for the console application.
//

#include "src/SharedHeaders.h"
#include <SFML/Graphics.hpp>
#include "src/render/Renderer.h"
#include "src/render/AssetLoader.h"

int _tmain(int argc, _TCHAR* argv[])
{
	auto assetLoader = std::make_shared<sqr::AssetLoader>();
	sqr::Renderer renderer(assetLoader);

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

