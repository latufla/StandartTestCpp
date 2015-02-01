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

long long getElapsedTimeMSec();

int _tmain(int argc, _TCHAR* argv[]) {
	auto assetLoader = std::make_shared<sqr::AssetLoader>();
	auto renderer = std::make_shared<sqr::RenderEngine>(assetLoader);

	auto world = std::make_shared<sqw::World>();

	auto color = glm::vec4{0.0f, 0.0f, 1.0f, 1.0f};
	sg::GameObject gameObject(renderer, world, 1, 1, glm::vec2{0.0f, 0.0f}, color);
	
	const uint32_t step = 1000 / 60;
	long long begin = getElapsedTimeMSec();
	bool running = true;
	while(running) {
		long long elapsedTime = getElapsedTimeMSec() - begin;
		if(elapsedTime >= step) {
			running = renderer->doStep(step);
			world->doStep(step);

			gameObject.doStep(step);

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


