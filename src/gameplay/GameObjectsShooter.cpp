#include "GameObjectsShooter.h"
#include "interface/IGameField.h"
#include <iostream>
#include "../gui/MainHudData.h"
#include <memory>

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
				score += object->getPoints();
				field->removeObject(id);
				
				auto mainHud = sRenderer->getMainHud();
				auto hudData = std::make_shared<sqr::MainHudData>();
				hudData->score = score;
				mainHud->update(hudData);
			}
		}

		return true;
	}

}
