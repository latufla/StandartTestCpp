#pragma once
#include "../../SharedHeaders.h"
#include <memory>
#include "IGameObject.h"
#include <unordered_map>
#include "IGameProcessor.h"

namespace sg {
	class IGameField {
	public:
		virtual void addObject(uint32_t id, std::shared_ptr<IGameObject> object) = 0;
		virtual void removeObject(uint32_t id) = 0;

		virtual void addProcessor(std::shared_ptr<IGameProcessor>) = 0;

		virtual bool doStep(long long step) = 0;

		virtual std::weak_ptr<sqr::IRenderEngine> getRenderer() = 0;
		virtual std::weak_ptr<sqw::IWorld> getWorld() = 0;

		virtual std::unordered_map<uint32_t, std::shared_ptr<IGameObject>>& getObjects() = 0;
	};
}

