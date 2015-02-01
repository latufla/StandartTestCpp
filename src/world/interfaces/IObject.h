#pragma once
#include "../../SharedHeaders.h"
#include <glm.hpp>

namespace sqw{
	class IObject {
	public:
		virtual glm::mat4& getTransform() = 0;
		virtual void setTransform(const glm::mat4&) = 0;

		virtual glm::vec2& getSpeed() = 0;
	};
}

