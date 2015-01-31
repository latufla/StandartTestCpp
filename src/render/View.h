#pragma once
#include "IView.h"

namespace sqr {
	class View : public IView{
	public:
		View() = delete;
		View(std::string modelKeyName, const std::array<float, 16>& transform);

		virtual ~View();

		virtual std::string getModelKeyName() override;

		virtual void setTransform(std::array<float, 16>) override;
		virtual std::array<float, 16>& getTransform() override;

	private:
		std::string modelKeyName;
		std::array<float, 16> transform;
	};
}

