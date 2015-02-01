#pragma once
#include "../../SharedHeaders.h"
#include <memory>

namespace sg {
	class IGameField;
	class IGameProcessor {
	public:
		virtual bool doStep(IGameField* field, long long step) = 0;
	};
}

