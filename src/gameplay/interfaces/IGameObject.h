#pragma once
#include "..\..\render\interfaces\IRenderEngine.h"
#include "..\..\world\interfaces\IWorld.h"

namespace sg{
class IGameObject {
	public:
		virtual bool doStep(long long step) = 0;

		virtual std::weak_ptr<sqr::IRenderEngine> getRenderer() = 0;		
		virtual std::weak_ptr<sqr::IView> getView() = 0;

		virtual std::weak_ptr<sqw::IWorld> getWorld() = 0;
		virtual std::weak_ptr<sqw::IObject> getWorldObject() = 0;


		virtual int32_t getPoints() = 0;
	};
}

