#pragma once
#include "interface\IGameProcessor.h"

namespace sg {
	class GameObjectsShooter : public IGameProcessor {
	public:
		GameObjectsShooter() = default;
		virtual ~GameObjectsShooter();

		virtual bool doStep(IGameEngine* field, long long step) override;
	protected:
		uint32_t score = 0;

		bool mouseDown = false;
		int32_t mouseDownObject = -1;
	};
}

