#pragma once
#include "../SharedHeaders.h"
#include <array>

namespace sqr {
	class IView {
	public:
		virtual void setTransform(std::array<float,16>) = 0;
		virtual std::string getModelKeyName() = 0;
	};
}