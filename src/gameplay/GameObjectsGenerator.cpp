#include "GameObjectsGenerator.h"
#include "GameObjectInfo.h"
#include "..\render\Model3d.h"
#include "GameObject.h"
#include "GameField.h"
#include <chrono>

using namespace std::chrono;

namespace sg {
	GameObjectsGenerator::GameObjectsGenerator() {		
		auto now = high_resolution_clock::now();
		auto mSec = duration_cast<milliseconds>(now.time_since_epoch());
		std::srand((uint32_t)mSec.count());
	}
	
	GameObjectsGenerator::~GameObjectsGenerator() {

	}


	bool GameObjectsGenerator::doStep(IGameField* field, long long step) { 
		elapsedTime += step;

		if(lastCreationTime + interval > elapsedTime)// its quite unreliable but the easiest way
			return false;
		
		lastCreationTime = elapsedTime;
				

		// we really should use Command pattern here
		const int32_t defaultPoints = 10;
		const float defaultColorSeed = 0.5f;
		const float defaultSpeed = -0.001f;
		
		auto objectInfo = std::make_shared<sg::GameObjectInfo>(); 
		objectInfo->modelName = sqr::Model3d::DEFAULT_MODEL;
		objectInfo->radius = .5f;
		objectInfo->points = (int32_t)(objectInfo->radius * defaultPoints);

		double greenSeed = (double)std::rand() / RAND_MAX;
		greenSeed = defaultColorSeed + (1.0f - defaultColorSeed) * greenSeed;

		double blueSeed = (double)std::rand() / RAND_MAX;
		blueSeed = defaultColorSeed + (1.0f - defaultColorSeed) * blueSeed;
		
		objectInfo->color = glm::vec4{0.0f, greenSeed, blueSeed, 1.0f};
		objectInfo->speed = glm::vec2{0.0f, objectInfo->radius * defaultSpeed};
		
		double posSeedX = (double)std::rand() / RAND_MAX;
		posSeedX = 2.0f * posSeedX - 1.0f;
		glm::vec2 position{posSeedX, 1.0f - objectInfo->radius};
		
		auto gameObject = std::make_shared<sg::GameObject>(field->getRenderer(), field->getWorld(), nextObjectId, objectInfo, position);
		field->addObject(nextObjectId, gameObject);
		
		nextObjectId++;

		return true;
	}
}

