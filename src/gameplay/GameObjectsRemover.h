#pragma once
#include "interface\IGameProcessor.h"

namespace sg {
	class GameObjectsRemover : public IGameProcessor{
	public:
		GameObjectsRemover() = default;
		virtual ~GameObjectsRemover();

		virtual bool doStep(IGameEngine* field, long long step) override;
	};
	
}
