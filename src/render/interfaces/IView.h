#pragma once
#include "../../SharedHeaders.h"
#include <array>
#include <glm.hpp>

namespace sqr {
	class IView {
	public:
		virtual std::string getModelKeyName() = 0;

		virtual void setTransform(glm::mat4&) = 0;
		virtual glm::mat4 getTransform() = 0;
		
		virtual void translate(float x, float y, float z) = 0;
		virtual void scale(float x, float y, float z) = 0;

		virtual std::array<float, 4>& getColor() = 0;
	};
}