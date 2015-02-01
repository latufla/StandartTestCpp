#pragma once
#include "interface\IGameProcessor.h"

namespace sg {
	class GameObjectsShooter : public IGameProcessor {
	public:
		GameObjectsShooter() = default;
		virtual ~GameObjectsShooter();

		virtual bool doStep(IGameField* field, long long step) override;
	protected:
		uint32_t score = 0;

		long long elapsedTime = 0;
		long long lastClickTime = 0;
		uint32_t interval = 100;
	};
}

