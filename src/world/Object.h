#pragma once
#include "interfaces\IObject.h"

namespace sw{
	class Object : public IObject{
	public:
		Object(const glm::mat4& transform, const glm::vec2& speed);
		virtual ~Object();

		virtual glm::mat4& getTransform() override;
		virtual void setTransform(const glm::mat4&) override;

		virtual glm::vec2& getSpeed() override;
	protected:
		glm::mat4 transform;
		glm::vec2 speed;
	};
}

