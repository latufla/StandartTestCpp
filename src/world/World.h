#pragma once
#include "interfaces\IWorld.h"
#include <unordered_map>

namespace sw{
	class World : public IWorld{
	public:
		World() = default;
		virtual ~World();

		virtual void addObject(uint32_t id, std::shared_ptr<IObject> object) override;
		virtual void removeObject(uint32_t id) override;

		virtual std::shared_ptr<IObject> getObjectBy(uint32_t id) override;
		virtual bool hasObject(uint32_t id) override;

		virtual bool doStep(long long step) override;

	protected:
		std::unordered_map<uint32_t, std::shared_ptr<IObject>> idToObject;
	};
}

