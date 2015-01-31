#include "View.h"

namespace sqr{	
	View::View(std::string modelKeyName, const std::array<float, 16>& transform) 
		: modelKeyName(modelKeyName), transform(transform) {

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
}
