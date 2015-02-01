#include "GameObjectsShooter.h"
#include "interface/IGameField.h"
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

		if(sRenderer->getMouseLeftDown()) { // we really should use Command pattern here
			int32_t id = sRenderer->getMouseOver();
			if(id != -1) {
				auto object = field->getObjectBy(id);				
				points += object->getPoints();
				field->removeObject(id);
			}
		}

		return true;
	}

}
