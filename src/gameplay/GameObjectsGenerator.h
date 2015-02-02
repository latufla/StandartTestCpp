#pragma once
#include "interface\IGameProcessor.h"

namespace sg {
	class GameObjectsGenerator : public IGameProcessor{
	public:
		GameObjectsGenerator();
		virtual ~GameObjectsGenerator();

		virtual bool doStep(IGameEngine* field, long long step) override;
	protected:		
		long long elapsedTime = 0;
		
		long long lastCreationTime = 0;
		
		uint32_t nextObjectId = 0;
		uint32_t interval = 1000;
	};
}

