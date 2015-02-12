#pragma once
#include "../../SharedHeaders.h"
#include <memory>
#include "IView.h"
#include "../../gui/interfaces/IMainHud.h"

namespace sr {
	class IRenderEngine {
	public:
		virtual void addObject(uint32_t id, std::shared_ptr<IView> object) = 0;
		virtual void removeObject(uint32_t id) = 0;

		virtual std::shared_ptr<IView> getObjectBy(uint32_t id) = 0;
		virtual bool hasObject(uint32_t id) = 0;

		virtual bool doStep(long long step) = 0;

		virtual bool getMouseLeftDown() = 0;
		virtual int32_t getMouseOver() = 0;

		virtual glm::vec2 getWindowSize() = 0;
	
		virtual std::shared_ptr<sr::IMainHud> getMainHud() = 0;
	};
}