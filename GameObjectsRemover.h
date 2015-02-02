#pragma once
#include "src\gameplay\interface\IGameProcessor.h"

class GameObjectsRemover : public sg::IGameProcessor {
public:
	GameObjectsRemover() = default;
	virtual ~GameObjectsRemover();

	virtual bool doStep(sg::IGameEngine* field, long long step) override;
};
