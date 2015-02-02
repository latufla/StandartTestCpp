#include "GameObjectsShooter.h"
#include <memory>
#include "src\gameplay\interface\IGameEngine.h"
#include "MainHudData.h"


GameObjectsShooter::~GameObjectsShooter() {
}

bool GameObjectsShooter::doStep(sg::IGameEngine* field, long long step) {
	auto renderer = field->getRenderer();

	int32_t mouseOverObject = renderer->getMouseOver();
	bool isMouseDown = renderer->getMouseLeftDown();
	if(!mouseDown && isMouseDown) { // key down
		mouseDown = true;
		mouseDownObject = mouseOverObject;
	}
		
	if(mouseDown && !isMouseDown) { // key up
		if(mouseOverObject != -1 && mouseDownObject == mouseOverObject) { // and over the same object
				
			// we really should use Command pattern here
				auto object = field->getObjectBy(mouseOverObject);
				score += object->getPoints();
				field->removeObject(mouseOverObject);

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
