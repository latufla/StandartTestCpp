#pragma once
#include "interface\IGameProcessor.h"

namespace sg {
	class GameObjectsGenerator : public IGameProcessor{
	public:
		GameObjectsGenerator() = default;
		virtual ~GameObjectsGenerator();

		virtual bool doStep(IGameField* field, long long step);
	protected:		
		long long elapsedTime = 0;
		
		long long lastCreationTime = 0;
		
		uint32_t nextObjectId = 0;
		uint32_t interval = 2000;

	};
}

