#include "Renderer.h"

using std::shared_ptr;

namespace sqr{
	Renderer::Renderer(shared_ptr<ILoader> assetLoader) 
		:assetLoader(assetLoader) {
	}
	
	Renderer::~Renderer() {
	}

	void Renderer::addObject(uint32_t id, shared_ptr<IView> object) {
		objects.emplace(id, object);
	}

	void Renderer::removeObject(uint32_t id) {
		objects.erase(id);
	}

	shared_ptr<IView> Renderer::getObjectBy(uint32_t id) {
		return objects.at(id);
	}

	bool Renderer::doStep(double step) {
		return true;
	}

}
