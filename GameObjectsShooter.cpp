#include "GameObjectsShooter.h"
#include <memory>
#include "src\gameplay\interfaces\IEngine.h"
#include "MainHudData.h"
#include "src\gameplay\commands\DestroyCommand.h"


GameObjectsShooter::~GameObjectsShooter() {
}

bool GameObjectsShooter::doStep(sg::IEngine* engine, long long step) {
	auto renderer = engine->getRenderer();

	int32_t mouseOverObject = renderer->getMouseOver();
	bool isMouseDown = renderer->getMouseLeftDown();
	if(!mouseDown && isMouseDown) { // key down
		mouseDown = true;
		mouseDownObject = mouseOverObject;
	}
		
	if(mouseDown && !isMouseDown) { // key up
		if(mouseOverObject != -1 && mouseDownObject == mouseOverObject) { // and over the same object	
			auto object = engine->getObjectBy(mouseOverObject);
			score += object->getPoints();

			sg::DestroyCommand destroy(engine, mouseOverObject);
			destroy.tryToExecute();

			auto mainHud = renderer->getMainHud();
			auto hudData = std::make_shared<MainHudData>();
			hudData->score = score;
			mainHud->update(hudData);
		}
		mouseDown = false;
		mouseDownObject = -1;
	}

	return true;
}
