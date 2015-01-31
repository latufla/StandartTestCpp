#pragma once
#include "../SharedHeaders.h"
#include <memory>
#include "IView.h"

namespace sqr {
	class IRenderer {
		virtual void addObject(uint32_t id, std::shared_ptr<IView> object) = 0;
		virtual void removeObject(uint32_t id) = 0;

		virtual std::shared_ptr<IView> getObjectBy(uint32_t id) = 0;

		virtual bool doStep(double step) = 0;
	};
}