#include "GameField.h"

namespace sg {
	GameField::GameField(std::weak_ptr<sqr::IRenderEngine> renderer, std::weak_ptr<sqw::IWorld> world) 
		: renderer(renderer), world(world){
	}
	
	GameField::~GameField() {
	}

	void GameField::addObject(uint32_t id, std::shared_ptr<IGameObject> object) {
		idToObject.emplace(id, object);
	}

	void GameField::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	void GameField::addProcessor(std::shared_ptr<IGameProcessor> processor) {
		processors.push_back(processor);
	}

	bool GameField::doStep(long long step) {
		for(auto i : processors) {
			i->doStep(this, step);
		}
		for(auto i : idToObject) {
			i.second->doStep(step);
		}
		return true;
	}

	std::weak_ptr<sqr::IRenderEngine> GameField::getRenderer() {
		return renderer;
	}

	std::weak_ptr<sqw::IWorld> GameField::getWorld() {
		return world;
	}

	std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& GameField::getObjects() {
		return idToObject;
	}

}
