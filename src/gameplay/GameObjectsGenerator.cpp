#include "GameObjectsGenerator.h"
#include "GameObjectInfo.h"
#include "..\render\Model3d.h"
#include "GameObject.h"
#include "GameField.h"

namespace sg {
	
	GameObjectsGenerator::~GameObjectsGenerator() {
	}

	bool GameObjectsGenerator::doStep(IGameField* field, long long step) { 
		elapsedTime += step;

		if(lastCreationTime + interval > elapsedTime)// its quite unreliable but the easiest way
			return false;
		
		lastCreationTime = elapsedTime;

		// we really should use Command pattern here
		auto objectInfo = std::make_shared<sg::GameObjectInfo>(); 
		objectInfo->modelName = sqr::Model3d::DEFAULT_MODEL;
		objectInfo->radius = 1.0f;
		objectInfo->points = 10;
		objectInfo->color = glm::vec4{0.0f, 0.0f, 1.0f, 1.0f};
		objectInfo->speed = glm::vec2{0.0f, -0.00001f};

		auto gameObject = std::make_shared<sg::GameObject>(field->getRenderer(), field->getWorld(), nextObjectId, objectInfo, glm::vec2{0.0f, 0.0f});
		field->addObject(nextObjectId, gameObject);
		
		nextObjectId++;

		return true;
	}

}

