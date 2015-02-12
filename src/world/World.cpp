#include "World.h"
#include <gtc/matrix_transform.hpp>
#include "../exceptions/Exception.h"

using std::shared_ptr;
using std::to_string;

using glm::vec3;
using glm::mat4;
using glm::translate;

namespace sw {
	
	World::~World() {
	}

	void World::addObject(uint32_t id, shared_ptr<IObject> object) {
		auto res = idToObject.emplace(id, object);
		if(!res.second)
			throw sx::InvalidKeyException(EXCEPTION_INFO, to_string(id));
	}

	void World::removeObject(uint32_t id) {
		idToObject.erase(id);
	}

	shared_ptr<IObject> World::getObjectBy(uint32_t id) {
		try {
			return idToObject.at(id);
		} catch(std::out_of_range&) {
			throw sx::InvalidKeyException(EXCEPTION_INFO, to_string(id));
		}
	}

	bool World::hasObject(uint32_t id) {
		return idToObject.find(id) != idToObject.cend();
	}

	bool World::doStep(long long step) {
		for(auto i : idToObject) {
			auto object = i.second;
			auto& transform = object->getTransform();
			auto& speed = object->getSpeed();
						
			vec3 delta{step * speed.x, step * speed.y, 0.0f};
			mat4 translation = translate(mat4{}, delta);

			object->setTransform(translation * transform);
		}
		return true;
	}
}
