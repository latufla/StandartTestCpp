#pragma once
#include "interfaces/IView.h"

namespace sqr {
	class View : public IView{
	public:
		View() = delete;
		View(std::string modelKeyName, const std::array<float, 4>& color);

		virtual ~View();

		virtual std::string getModelKeyName() override;

		virtual void setTransform(std::array<float, 16>) override;
		virtual std::array<float, 16>& getTransform() override;

		virtual std::array<float, 4>& getColor() override;

		virtual void translate(float x, float y, float z) override;
		virtual void scale(float x, float y, float z) override;
	private:
		std::string modelKeyName;
		std::array<float, 16> transform;

		std::array<float, 4> color;
	};
}

