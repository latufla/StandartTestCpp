#pragma once
#include "src\gameplay\interface\IGameProcessor.h"

class GameObjectsGenerator : public sg::IGameProcessor {
public:
	GameObjectsGenerator();
	virtual ~GameObjectsGenerator();

	virtual bool doStep(sg::IGameEngine* field, long long step) override;
protected:
	long long elapsedTime = 0;

	long long lastCreationTime = 0;

	uint32_t nextObjectId = 0;
	uint32_t interval = 1000;
};

