#pragma once
#include "../SharedHeaders.h"
#include <array>

namespace sqr {
	class IView {
	public:
		virtual std::string getModelKeyName() = 0;

		virtual void setTransform(std::array<float, 16>) = 0;
		virtual std::array<float, 16>& getTransform() = 0;
	};
}