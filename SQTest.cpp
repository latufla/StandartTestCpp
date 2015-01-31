// SQTest.cpp : Defines the entry point for the console application.
//

#include "src/SharedHeaders.h"
#include "src/render/Renderer.h"
#include "src/render/AssetLoader.h"
#include "src/render/View.h"
#include "src/render/Model3d.h"
#include <chrono>

long long getElapsedTimeMSec();

int _tmain(int argc, _TCHAR* argv[]) {
	auto assetLoader = std::make_shared<sqr::AssetLoader>();
	sqr::Renderer renderer(assetLoader);

	std::array<float, 16> transform;
	auto view = std::make_shared<sqr::View>(sqr::Model3d::DEFAULT_MODEL, transform);
	renderer.addObject(1, view);

	const uint32_t step = 1000 / 60;
	long long begin = getElapsedTimeMSec();
	bool running = true;
	while(running) {
		long long elapsedTime = getElapsedTimeMSec() - begin;
		if(elapsedTime >= step) {
			running = renderer.doStep(step);
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


