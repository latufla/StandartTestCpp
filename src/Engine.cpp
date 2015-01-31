#include "Engine.h"


namespace sqw {
	Engine::~Engine() {
	}

	Engine::Engine(std::shared_ptr<sqr::IRenderEngine> rendred, std::shared_ptr<sqw::IWorld> world)
		: renderer(renderer), world(world) {

	}

	bool Engine::doStep(long long step) {
		bool success = renderer->doStep(step);
		world->doStep(step);

		return success;
	}

}
