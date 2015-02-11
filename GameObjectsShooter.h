#pragma once
#include "src\gameplay\interfaces\IProcessor.h"


class GameObjectsShooter : public sg::IProcessor {
public:
	GameObjectsShooter() = default;
	virtual ~GameObjectsShooter();

	virtual bool doStep(sg::IEngine* engine, long long step) override;
protected:
	uint32_t score = 0;

	bool mouseDown = false;
	int32_t mouseDownObject = -1;
};

