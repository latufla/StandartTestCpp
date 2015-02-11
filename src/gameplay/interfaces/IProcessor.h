#pragma once
#include "../../SharedHeaders.h"
#include <memory>

namespace sg {
	class IEngine;
	class IProcessor {
	public:
		virtual bool doStep(IEngine* engine, long long step) = 0; // sorry, rapid
	};
}

