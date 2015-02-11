// SQTest.cpp : Defines the entry point for the console application.
//

#include "src/SharedHeaders.h"
#include "src/render/Renderer.h"
#include "src/render/AssetLoader.h"
#include <chrono>
#include "src/world/World.h"
#include "src/gameplay/GameObject.h"
#include "src/gameplay/GameObjectInfo.h"
#include "src/gameplay/Engine.h"
#include "GameObjectsGenerator.h"
#include "GameObjectsShooter.h"
#include "GameObjectsRemover.h"
#include "MainHud.h"

// may have issues here
#include <thread>

long long getElapsedTimeMSec();
void sleep(long long interval);

int _tmain(int argc, _TCHAR* argv[]) {
	auto assetLoader = std::make_shared<sqr::AssetLoader>();
	auto mainHud = std::make_shared <MainHud>(assetLoader);
	auto renderer = std::make_shared<sqr::Renderer>(assetLoader, mainHud);

	auto world = std::make_shared<sqw::World>();
	
	auto gameField = std::make_shared<sg::Engine>(renderer, world);
	
	auto generator = std::make_shared<GameObjectsGenerator>();
	gameField->addProcessor(generator);
	
	auto shooter = std::make_shared<GameObjectsShooter>();
	gameField->addProcessor(shooter);

	auto eol = std::make_shared<GameObjectsRemover>();
	gameField->addProcessor(eol);
	
	const uint32_t step = 1000 / 60;
	long long lastStepTime = getElapsedTimeMSec();
	bool running = true;
	while(running) {
		long long elapsedTime = getElapsedTimeMSec() - lastStepTime;
		if(elapsedTime >= step) {						
			running = gameField->doStep(step);
			lastStepTime = getElapsedTimeMSec() - (elapsedTime - step);
		}
		else {
			sleep(step - elapsedTime);
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

// this_thread may not work on mobile
// so fork it
void sleep(long long interval) {
	std::this_thread::sleep_for(std::chrono::milliseconds(interval));
}


