#include "View.h"

namespace sqr{	
	View::View(std::string modelKeyName, const std::array<float, 4>& color) 
		: modelKeyName(modelKeyName), color(color) {

		for(uint8_t i = 0; i < transform.size(); i++) {
			transform[i] = 0;
		}
		scale(1.0f, 1.0f, 1.0f);
	}

	View::~View() {
	}
	
	std::string View::getModelKeyName() {
		return modelKeyName;
	}

	void View::setTransform(std::array<float, 16> val) {
		transform = val;
	}

	std::array<float, 16>& View::getTransform() {
		return transform;
	}

	std::array<float, 4>& View::getColor() {
		return color;
	}

	void View::translate(float x, float y, float z) {
		transform[12] = x;
		transform[13] = y;
		transform[14] = z;
	}

	void View::scale(float x, float y, float z) {
		transform[0] = x;
		transform[5] = y;
		transform[10] = z;
		transform[15] = 1.0f;
	}
}
