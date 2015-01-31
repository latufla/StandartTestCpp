#include "Renderer.h"

using std::shared_ptr;

namespace sqr{
	Renderer::Renderer(shared_ptr<ILoader> assetLoader) 
		:assetLoader(assetLoader) {
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
		return true;
	}

}
