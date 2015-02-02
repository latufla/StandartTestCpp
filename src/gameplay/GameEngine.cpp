#include "GameEngine.h"

namespace sg {
	GameEngine::GameEngine(std::shared_ptr<sqr::IRenderEngine> renderer, std::shared_ptr<sqw::IWorld> world)
		: renderer(renderer), world(world){
	}
	
	GameEngine::~GameEngine() {
	}

	void GameEngine::addObject(uint32_t id, std::shared_ptr<IGameObject> object) {
		idToObject.emplace(id, object);
	}

	void GameEngine::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	std::shared_ptr<IGameObject> GameEngine::getObjectBy(uint32_t id) {
		return idToObject.at(id);
	}
	
	void GameEngine::addProcessor(std::shared_ptr<IGameProcessor> processor) {
		processors.push_back(processor);
	}

	bool GameEngine::doStep(long long step) {
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

	std::shared_ptr<sqr::IRenderEngine> GameEngine::getRenderer() {
		return renderer;
	}

	std::shared_ptr<sqw::IWorld> GameEngine::getWorld() {
		return world;
	}

	std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& GameEngine::getObjects() {
		return idToObject;
	}
}
