#pragma once
#include "../../SharedHeaders.h"
#include <vector>
#include <memory>
#include <glm.hpp>

namespace sqr {
	class IVertex3d { // sorry bout that - max extensibility, min c++ 
	public:
		virtual glm::vec3& getPosition() = 0;
	};

	class IMesh3d {
	public:
		virtual std::string getName() = 0;

		virtual std::vector<std::shared_ptr<IVertex3d>>& getVertices() = 0;
		virtual std::vector<float>& getRawVertices() = 0;
		
		virtual std::vector<uint16_t>& getIndices() = 0;
	};
}