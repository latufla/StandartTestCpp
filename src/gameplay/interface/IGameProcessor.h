#pragma once
#include "../../SharedHeaders.h"
#include <memory>

namespace sg {
	class IGameEngine;
	class IGameProcessor {
	public:
		virtual bool doStep(IGameEngine* field, long long step) = 0;
	};
}

