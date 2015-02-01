// SQTest.cpp : Defines the entry point for the console application.
//

#include "src/SharedHeaders.h"
#include "src/render/RenderEngine.h"
#include "src/render/AssetLoader.h"
#include "src/render/View.h"
#include "src/render/Model3d.h"
#include <chrono>
#include "src/world/World.h"
#include "src/world/Object.h"
#include "src/gameplay/GameObject.h"
#include "src/gameplay/GameObjectInfo.h"
#include "src/gameplay/GameField.h"
#include "src/gameplay/GameObjectsGenerator.h"
#include "src/gameplay/GameObjectsShooter.h"

long long getElapsedTimeMSec();

int _tmain(int argc, _TCHAR* argv[]) {
	auto assetLoader = std::make_shared<sqr::AssetLoader>();
	auto renderer = std::make_shared<sqr::RenderEngine>(assetLoader);

	auto world = std::make_shared<sqw::World>();
	
	auto gameField = std::make_shared<sg::GameField>(renderer, world);
	
	auto generator = std::make_shared<sg::GameObjectsGenerator>();
	gameField->addProcessor(generator);
	
	auto shooter = std::make_shared<sg::GameObjectsShooter>();
	gameField->addProcessor(shooter);

	const uint32_t step = 1000 / 60; // don`t float it
	long long begin = getElapsedTimeMSec();
	bool running = true;
	while(running) {
		long long elapsedTime = getElapsedTimeMSec() - begin;
		if(elapsedTime >= step) {			
			world->doStep(step);
			running = renderer->doStep(step);

			gameField->doStep(step);

			begin = getElapsedTimeMSec() - (elapsedTime - step);
		}
	}
	return 0;
}

long long getElapsedTimeMSec() {
	using namespace std::chrono;
	auto now = high_resolution_clock::now();
	auto mSec = duration_cast<milliseconds>(now.time_since_epoch());
	return mSec.count();
}


