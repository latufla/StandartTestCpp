#pragma once
#include "../SharedHeaders.h"
#include <vector>
#include <memory>
#include <array>

namespace sqr {
	class IVertex3d {
		virtual std::array<float, 3>& getPosition() = 0;
	};

	class IMesh3d {
		virtual std::vector<std::shared_ptr<IVertex3d>> getVertices() = 0;
		virtual std::vector<uint16_t> getIndices() = 0;
	};
}