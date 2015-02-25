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

#include "src/exceptions/Exception.h"
#include <iostream>

void run();
void handleExceptions();

long long getElapsedTimeMSec();
void sleep(long long interval);

int _tmain(int argc, _TCHAR* argv[]) {
	try {
		run();
	} catch(...) {
		handleExceptions();
	}

	return 0;
}

void run() {
	auto assetLoader = std::make_shared<sr::AssetLoader>();
	auto mainHud = std::make_shared <MainHud>(assetLoader);
	auto renderer = std::make_shared<sr::Renderer>(assetLoader, mainHud);

	auto world = std::make_shared<sw::World>();

	auto gameField = std::make_shared<sg::Engine>(renderer, world);

	auto generator = std::make_shared<GameObjectsGenerator>();
	gameField->addProcessor(generator);

	auto shooter = std::make_shared<GameObjectsShooter>();
	gameField->addProcessor(shooter);

	auto eol = std::make_shared<GameObjectsRemover>();
	gameField->addProcessor(eol);

	long long step = 1000 / 30;
	bool running = true;
	while(running) {
		long long startTime = getElapsedTimeMSec();
		running = gameField->doStep(step);
		step = getElapsedTimeMSec() - startTime;
	}
}

void handleExceptions() {
	std::string error = "";
	try {
		throw;
	} catch(sx::Exception& e) {
		error = e.msg();
	} catch(std::exception& e) {
		error = e.what();
	} catch(...) {
		error = "unknown exception";
	}

	if(error != "") {
		std::cout << error;
		std::exit(1);
	}
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

