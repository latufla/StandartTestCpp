#pragma once
#include "..\..\render\interfaces\IRenderEngine.h"
#include "..\..\world\interfaces\IWorld.h"

namespace sg{
class IGameObject {
	public:
		virtual bool doStep(long long step) = 0;

		virtual std::weak_ptr<sr::IRenderEngine> getRenderer() = 0;		
		virtual std::weak_ptr<sr::IView> getView() = 0;

		virtual std::weak_ptr<sw::IWorld> getWorld() = 0;
		virtual std::weak_ptr<sw::IObject> getWorldObject() = 0;


		virtual int32_t getPoints() = 0;
	};
}

