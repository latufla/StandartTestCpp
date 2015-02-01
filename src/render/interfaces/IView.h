#pragma once
#include "../../SharedHeaders.h"
#include <glm.hpp>
#include <string>

namespace sqr {
	class IView {
	public:
		virtual std::string getModelKeyName() = 0;

		virtual void setTransform(glm::mat4&) = 0;
		virtual glm::mat4 getTransform() = 0;

		virtual glm::vec4& getColor() = 0;
	};
}