#include "GameObjectsGenerator.h"
#include <chrono>
#include <gtc/matrix_transform.hpp>
#include "src/gameplay/interfaces/IEngine.h"
#include "src/gameplay/GameObjectInfo.h"
#include "src/render/Model3d.h"
#include "src/gameplay/GameObject.h"
#include "src/gameplay/commands/CreateCommand.h"

using namespace std::chrono;

GameObjectsGenerator::GameObjectsGenerator() {
	auto now = high_resolution_clock::now();
	auto mSec = duration_cast<milliseconds>(now.time_since_epoch());
	std::srand((uint32_t)mSec.count());
}

GameObjectsGenerator::~GameObjectsGenerator() {

}


bool GameObjectsGenerator::doStep(sg::IEngine* engine, long long step) {
	elapsedTime += step;

	if(lastCreationTime + interval > elapsedTime)// its quite unreliable but the easiest way
		return true;

	lastCreationTime = elapsedTime;


	const double defaultRadius = 0.1;
	const int32_t defaultPoints = 4;
	const double defaultColorSeed = 0.5;
	const double defaultSpeed = -0.0001;

	auto objectInfo = std::make_shared<sg::GameObjectInfo>();
	objectInfo->modelName = sr::Model3d::DEFAULT_MODEL;

	double rndRadius = (double)std::rand() / RAND_MAX;
	objectInfo->radius = (float)(defaultRadius + (0.4 - defaultRadius) * rndRadius);
	objectInfo->points = (int32_t)(defaultPoints / objectInfo->radius);

	double rndGreen = (double)std::rand() / RAND_MAX;
	rndGreen = defaultColorSeed + (1.0 - defaultColorSeed) * rndGreen;

	double rndBlue = (double)std::rand() / RAND_MAX;
	rndBlue = defaultColorSeed + (1.0 - defaultColorSeed) * rndBlue;

	objectInfo->color = glm::vec4{0.0, rndGreen, rndBlue, 1.0};
	objectInfo->speed = glm::vec2{0.0, defaultSpeed / objectInfo->radius};

	auto renderer = engine->getRenderer();
	auto wSize = renderer->getWindowSize();

	double ratio = (double)wSize.x / (double)wSize.y;
	ratio -= objectInfo->radius;
	double rndX = 0.0;
	if(ratio > 0.0) {
		double a = -ratio;
		double b = ratio;
		double rnd = ((double)rand()) / (double)RAND_MAX;
		rndX = a + rnd * (b - a);
	}

	glm::vec3 position{rndX, 1.0 - objectInfo->radius, 0.0};	
	glm::vec3 scaling{objectInfo->radius, objectInfo->radius, 0.0};
	glm::mat4 transform = glm::translate(glm::mat4{}, position) * glm::scale(glm::mat4{}, scaling);
	
	sg::CreateCommand create(engine, objectInfo, transform);
	return create.tryToExecute();
}

