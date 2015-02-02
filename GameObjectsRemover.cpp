#include "GameObjectsRemover.h"
#include "src\gameplay\interface\IGameEngine.h"


GameObjectsRemover::~GameObjectsRemover() {
}

bool GameObjectsRemover::doStep(sg::IGameEngine* field, long long step) {

	// we really should use Command pattern here
	std::vector<uint32_t> objectToRemove;
	for(auto& i : field->getObjects()) {
		auto id = i.first;
		auto object = i.second;
		auto worldObject = object->getWorldObject();

		auto sWorldObject = worldObject.lock();
		auto transform = sWorldObject->getTransform();

		// dirty, but handy
		float radius = transform[0].x; // uniform scale, circles only stuff
		float y = transform[3].y;
		//

		if(y - radius < -1.0f) {
			objectToRemove.push_back(id);
		}
	}

	for(auto& i : objectToRemove) {
		field->removeObject(i);
	}

	return true;
}

