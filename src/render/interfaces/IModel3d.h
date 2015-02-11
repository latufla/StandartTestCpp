#pragma once
#include "../../SharedHeaders.h"
#include <vector>
#include <memory>
#include "IMesh3d.h"

namespace sqr {
	class IModel3d {
	public:
		virtual std::vector<std::shared_ptr<IMesh3d>>& getMeshes() = 0;
		virtual std::shared_ptr<IMesh3d>& getHitMesh() = 0;

		virtual std::string getKeyName() = 0;
	};
}