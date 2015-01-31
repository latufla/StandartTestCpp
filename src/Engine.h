#pragma once
#include "render\interfaces\IRenderEngine.h"
#include "world\interfaces\IWorld.h"
#include "IEngine.h"
#include <memory>

namespace sqw {
	class Engine : public IEngine{
	public:
		Engine() = default;
		Engine(std::shared_ptr<sqr::IRenderEngine> rendred, std::shared_ptr<sqw::IWorld> world);
	
		virtual ~Engine();

		virtual bool doStep(long long step) = 0;

	protected:
		std::shared_ptr<sqr::IRenderEngine> renderer;
		std::shared_ptr<sqw::IWorld> world;
	};
}

