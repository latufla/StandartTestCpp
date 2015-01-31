#pragma once
#include "../SharedHeaders.h"
#include <memory>
#include "IModel3d.h"

namespace sqr {
	class ILoader {
		virtual std::shared_ptr<IModel3d> getModel3d() = 0;
	};
}