#pragma once
#include "src\gameplay\interface\IGameProcessor.h"


class GameObjectsShooter : public sg::IGameProcessor {
public:
	GameObjectsShooter() = default;
	virtual ~GameObjectsShooter();

	virtual bool doStep(sg::IGameEngine* field, long long step) override;
protected:
	uint32_t score = 0;

	bool mouseDown = false;
	int32_t mouseDownObject = -1;
};

