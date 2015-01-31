#include "Renderer.h"
#include <SFML/OpenGL.hpp>

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
		// we should load geometry to gpu here
	}

	void Renderer::removeObject(uint32_t id) {
		idToObject.erase(id);
		// we should unload geometry from gpu here
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
		
		window->clear(sf::Color::Black);
		
		glDisable(GL_LIGHTING);
		glViewport(0, 0, window->getSize().x, window->getSize().y);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);

		for(auto& i : idToObject) {
			auto view = i.second;
			auto key = view->getModelKeyName();
			auto model = assetLoader->getModel3dBy(key);
			auto meshes = model->getMeshes();
			for(auto j : meshes) {
				auto vertices = j->getVertices();				
				auto color = view->getColor(); 
				
				std::vector<float> vxs;
				std::vector<float> colors;
				for(auto k : vertices) {
					auto pos = k->getPosition();
					vxs.push_back(pos[0]);
					vxs.push_back(pos[1]);
					vxs.push_back(pos[2]);
					colors.push_back(color[0]);
					colors.push_back(color[1]);
					colors.push_back(color[2]);
					colors.push_back(color[3]);
				}
				
				glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), &vxs[0]);
				glColorPointer(4, GL_FLOAT, 4 * sizeof(GLfloat), &colors[0]);
				
				auto transform = view->getTransform();
				glLoadMatrixf(&transform[0]);

				glDrawArrays(GL_TRIANGLES, 0, 6);
			}
		}
		window->display();

		return true;
	}

}
