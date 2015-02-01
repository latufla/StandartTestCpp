#include "World.h"
#include <iostream>

using std::shared_ptr;

namespace sqw {
	
	World::~World() {
	}

	void World::addObject(uint32_t id, shared_ptr<IObject> object) {
		idToObject.emplace(id, object);

	}

	void World::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	shared_ptr<IObject> World::getObjectBy(uint32_t id) {
		return idToObject.at(id);
	}

	bool World::doStep(long long step) {
		for(auto i : idToObject) {
			auto object = i.second;
			auto& pos = object->getPosition();
			auto& speed = object->getSpeed();
			pos.y += step * speed.y;
		}
		return true;
	}
}
