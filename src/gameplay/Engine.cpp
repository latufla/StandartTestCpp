#include "Engine.h"

namespace sg {
	Engine::Engine(std::shared_ptr<sqr::IRenderEngine> renderer, std::shared_ptr<sqw::IWorld> world)
		: renderer(renderer), world(world){
	}
	
	Engine::~Engine() {
	}

	void Engine::addObject(uint32_t id, std::shared_ptr<IGameObject> object) {
		idToObject.emplace(id, object);
	}

	void Engine::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	std::shared_ptr<IGameObject> Engine::getObjectBy(uint32_t id) {
		return idToObject.at(id);
	}
	
	void Engine::addProcessor(std::shared_ptr<IProcessor> processor) {
		processors.push_back(processor);
	}

	bool Engine::doStep(long long step) {
		if(!renderer->doStep(step))
			return false;

		world->doStep(step);

		for(auto i : processors) {
			i->doStep(this, step);
		}
		for(auto i : idToObject) {
			i.second->doStep(step);
		}
		return true;
	}

	std::shared_ptr<sqr::IRenderEngine> Engine::getRenderer() {
		return renderer;
	}

	std::shared_ptr<sqw::IWorld> Engine::getWorld() {
		return world;
	}

	std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& Engine::getObjects() {
		return idToObject;
	}
}
