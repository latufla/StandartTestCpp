#include "GameObjectsRemover.h"
#include "src\gameplay\interfaces\IEngine.h"
#include "src\gameplay\commands\DestroyCommand.h"


GameObjectsRemover::~GameObjectsRemover() {
}

bool GameObjectsRemover::doStep(sg::IEngine* engine, long long step) {
	std::vector<uint32_t> objectToRemove;
	for(auto& i : engine->getObjects()) {
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
		sg::DestroyCommand destroy(engine, i);
		destroy.tryToExecute();
	}

	return true;
}

