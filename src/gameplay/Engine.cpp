#include "Engine.h"
#include "..\exceptions\Exception.h"

using std::to_string;

namespace sg {
	Engine::Engine(std::shared_ptr<sr::IRenderEngine> renderer, std::shared_ptr<sw::IWorld> world)
		: renderer(renderer), world(world){
	}
	
	Engine::~Engine() {
	}

	void Engine::addObject(uint32_t id, std::shared_ptr<IGameObject> object) {
		auto res = idToObject.emplace(id, object);
		if(!res.second)
			throw sx::InvalidKeyException(EXCEPTION_INFO, to_string(id));
	}

	void Engine::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	std::shared_ptr<IGameObject> Engine::getObjectBy(uint32_t id) {
		try {
			return idToObject.at(id);
		} catch(std::out_of_range&) {
			throw sx::InvalidKeyException(EXCEPTION_INFO, to_string(id));
		}
	}

	bool Engine::hasObject(uint32_t id) {
		return idToObject.find(id) != idToObject.cend();
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

	std::shared_ptr<sr::IRenderEngine> Engine::getRenderer() {
		return renderer;
	}

	std::shared_ptr<sw::IWorld> Engine::getWorld() {
		return world;
	}

	std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& Engine::getObjects() {
		return idToObject;
	}
}
