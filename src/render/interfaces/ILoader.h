#pragma once
#include "../../SharedHeaders.h"
#include <memory>
#include "IModel3d.h"

namespace sqr {
	class ILoader {
	public:
		virtual std::shared_ptr<IModel3d> getModel3dBy(std::string keyName) = 0;
	};
}