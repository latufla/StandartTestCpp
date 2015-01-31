#pragma once
#include "../../SharedHeaders.h"
#include <glm.hpp>

namespace sqw{
	class IObject {
	public:
		virtual glm::vec2& getSpeed() = 0;
		virtual glm::vec2& getPosition() = 0;
	};
}

