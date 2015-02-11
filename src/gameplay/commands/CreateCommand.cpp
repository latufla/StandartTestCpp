#include "CreateCommand.h"
#include "..\GameObject.h"

using std::shared_ptr;

namespace sg {
	uint32_t CreateCommand::nextObjectId = 0;

	CreateCommand::CreateCommand(IEngine* engine, shared_ptr<GameObjectInfo> objectInfo, glm::mat4& transform)
		: Command(engine), objectInfo(objectInfo), transform(transform) {
	}

	CreateCommand::~CreateCommand() {
	}

	void CreateCommand::execute() {
		auto object = std::make_shared<GameObject>(engine->getRenderer(), engine->getWorld(), nextObjectId, objectInfo, transform);
		engine->addObject(nextObjectId, object);
		nextObjectId++;
	}
}
