#include "GameObjectsGenerator.h"
#include "GameObjectInfo.h"
#include "..\render\Model3d.h"
#include "GameObject.h"
#include "GameField.h"
#include <chrono>
#include <gtc/matrix_transform.hpp>

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
			return true;
		
		lastCreationTime = elapsedTime;
				

		// we really should use Command pattern here
		const float defaultRadius = 0.1f;
		const int32_t defaultPoints = 4;
		const float defaultColorSeed = 0.5f;
		const float defaultSpeed = -0.0001f;
		
		auto objectInfo = std::make_shared<sg::GameObjectInfo>(); 
		objectInfo->modelName = sqr::Model3d::DEFAULT_MODEL;
		double radiusSeed = (double)std::rand() / RAND_MAX;
		objectInfo->radius = defaultRadius + (0.4f - defaultRadius) * radiusSeed;
		objectInfo->points = (int32_t)(defaultPoints / objectInfo->radius);

		double greenSeed = (double)std::rand() / RAND_MAX;
		greenSeed = defaultColorSeed + (1.0f - defaultColorSeed) * greenSeed;

		double blueSeed = (double)std::rand() / RAND_MAX;
		blueSeed = defaultColorSeed + (1.0f - defaultColorSeed) * blueSeed;
		
		objectInfo->color = glm::vec4{0.0f, greenSeed, blueSeed, 1.0f};
		objectInfo->speed = glm::vec2{0.0f, defaultSpeed / objectInfo->radius};
		
		double x = (double)std::rand() / RAND_MAX;
		x = 2.0f * x - 1.0f;
		glm::vec3 position{x, 1.0f - objectInfo->radius, 0.0f};
		
		glm::vec3 scaling{objectInfo->radius, objectInfo->radius, 0.0f};
	
		glm::mat4 transform = glm::translate(glm::mat4{}, position) * glm::scale(glm::mat4{}, scaling);
		auto gameObject = std::make_shared<sg::GameObject>(field->getRenderer(), field->getWorld(), nextObjectId, objectInfo, transform);
		field->addObject(nextObjectId, gameObject);
		

		nextObjectId++;

		return true;
	}
}

