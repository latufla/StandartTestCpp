#pragma once
#include "../../SharedHeaders.h"
#include <memory>
#include "IGameObject.h"
#include <unordered_map>
#include "IProcessor.h"

namespace sg {
	class IEngine {
	public:
		virtual void addObject(uint32_t id, std::shared_ptr<IGameObject> object) = 0;
		virtual void removeObject(uint32_t id) = 0;

		virtual std::shared_ptr<IGameObject> getObjectBy(uint32_t id) = 0;
		virtual bool hasObject(uint32_t id) = 0;

		virtual void addProcessor(std::shared_ptr<IProcessor>) = 0;

		virtual bool doStep(long long step) = 0;

		virtual std::shared_ptr<sr::IRenderEngine> getRenderer() = 0;
		virtual std::shared_ptr<sw::IWorld> getWorld() = 0;

		virtual std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& getObjects() = 0;
	};
}

