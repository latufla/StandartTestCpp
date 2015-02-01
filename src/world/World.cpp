#include "World.h"
#include <gtc/matrix_transform.hpp>

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
			auto& transform = object->getTransform();
			auto& speed = object->getSpeed();
			glm::vec3 delta{step * speed.x, step * speed.y, 0.0f};
			object->setTransform(glm::translate(transform, delta));
		}
		return true;
	}
}
