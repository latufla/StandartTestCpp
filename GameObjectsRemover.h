#pragma once
#include "src\gameplay\interfaces\IProcessor.h"

class GameObjectsRemover : public sg::IProcessor {
public:
	GameObjectsRemover() = default;
	virtual ~GameObjectsRemover();

	virtual bool doStep(sg::IEngine* engine, long long step) override;
};
