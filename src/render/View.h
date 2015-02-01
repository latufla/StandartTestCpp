#pragma once
#include "interfaces/IView.h"

namespace sqr {
	class View : public IView{
	public:
		View() = delete;
		View(std::string modelKeyName, const glm::vec4& color);

		virtual ~View();

		virtual std::string getModelKeyName() override;

		virtual void setTransform(glm::mat4&) override;
		virtual glm::mat4 getTransform() override;

		virtual glm::vec4& getColor() override;
	protected:
		std::string modelKeyName;
		glm::mat4 transform;

		glm::vec4 color;
	};
}

