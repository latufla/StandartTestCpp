#pragma once
#include "src\gameplay\interfaces\IProcessor.h"

class GameObjectsGenerator : public sg::IProcessor {
public:
	GameObjectsGenerator();
	virtual ~GameObjectsGenerator();

	virtual bool doStep(sg::IEngine* engine, long long step) override;
protected:
	long long elapsedTime = 0;

	long long lastCreationTime = 0;

	uint32_t nextObjectId = 0;
	uint32_t interval = 1000;
};

