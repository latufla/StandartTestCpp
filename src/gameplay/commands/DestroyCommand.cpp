#include "DestroyCommand.h"


namespace sg {
	DestroyCommand::DestroyCommand(IEngine* engine, uint32_t objectId) 
		: Command(engine), objectId(objectId){
	}

	DestroyCommand::~DestroyCommand() {
	}

	bool DestroyCommand::canExecute() {
		return engine->hasObject(objectId);
	}

	void DestroyCommand::execute() {
		engine->removeObject(objectId);
	}
}
