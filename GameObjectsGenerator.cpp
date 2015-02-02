#include "GameObjectsGenerator.h"
#include <chrono>
#include <gtc/matrix_transform.hpp>
#include "src/gameplay/interface/IGameEngine.h"
#include "src/gameplay/GameObjectInfo.h"
#include "src/render/Model3d.h"
#include "src/gameplay/GameObject.h"

using namespace std::chrono;

GameObjectsGenerator::GameObjectsGenerator() {
	auto now = high_resolution_clock::now();
	auto mSec = duration_cast<milliseconds>(now.time_since_epoch());
	std::srand((uint32_t)mSec.count());
}

GameObjectsGenerator::~GameObjectsGenerator() {

}


bool GameObjectsGenerator::doStep(sg::IGameEngine* field, long long step) {
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

	double rndRadius = (double)std::rand() / RAND_MAX;
	objectInfo->radius = defaultRadius + (0.4f - defaultRadius) * rndRadius;
	objectInfo->points = (int32_t)(defaultPoints / objectInfo->radius);

	double rndGreen = (double)std::rand() / RAND_MAX;
	rndGreen = defaultColorSeed + (1.0f - defaultColorSeed) * rndGreen;

	double rndBlue = (double)std::rand() / RAND_MAX;
	rndBlue = defaultColorSeed + (1.0f - defaultColorSeed) * rndBlue;

	objectInfo->color = glm::vec4{0.0f, rndGreen, rndBlue, 1.0f};
	objectInfo->speed = glm::vec2{0.0f, defaultSpeed / objectInfo->radius};

	double rndX = (double)std::rand() / RAND_MAX;
	rndX = 2.0f * rndX - 1.0f;
	glm::vec3 position{rndX, 1.0f - objectInfo->radius, 0.0f};

	glm::vec3 scaling{objectInfo->radius, objectInfo->radius, 0.0f};

	glm::mat4 transform = glm::translate(glm::mat4{}, position) * glm::scale(glm::mat4{}, scaling);
	auto gameObject = std::make_shared<sg::GameObject>(field->getRenderer(), field->getWorld(), nextObjectId, objectInfo, transform);
	field->addObject(nextObjectId, gameObject);


	nextObjectId++;

	return true;
}

