#include "Renderer.h"

using std::shared_ptr;


namespace sqr{
	Renderer::Renderer(shared_ptr<ILoader> assetLoader) 
		:assetLoader(assetLoader) {

		window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768), "SFML");
	}
	
	Renderer::~Renderer() {
	}

	void Renderer::addObject(uint32_t id, shared_ptr<IView> object) {
		idToObject.emplace(id, object);
	}

	void Renderer::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	shared_ptr<IView> Renderer::getObjectBy(uint32_t id) {
		return idToObject.at(id);
	}

	bool Renderer::doStep(double step) {
		if(!window->isOpen())
			return false;

		sf::Event event;
		while(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		window->display();

		return true;
	}

}
