#include "GameObjectsShooter.h"
#include "interface/IGameField.h"
#include "../gui/MainHudData.h"
#include <memory>
#include <iostream>

namespace sg{
	GameObjectsShooter::~GameObjectsShooter() {
	}

	bool GameObjectsShooter::doStep(IGameField* field, long long step) {
		auto renderer = field->getRenderer();
		auto sRenderer = renderer.lock();
		if(!sRenderer)
			return false;

		auto world = field->getWorld();
		auto sWorld = world.lock();
		if(!sWorld)
			return false;
		

		int32_t mouseOverObject = sRenderer->getMouseOver();
		bool isMouseDown = sRenderer->getMouseLeftDown();
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

					auto mainHud = sRenderer->getMainHud();
					auto hudData = std::make_shared<sqr::MainHudData>();
					hudData->score = score;
					mainHud->update(hudData);
			}
			mouseDown = false;
			mouseDownObject = -1;
		}

		return true;
	}

}
