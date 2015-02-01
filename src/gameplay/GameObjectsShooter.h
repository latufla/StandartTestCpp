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
	};
}

