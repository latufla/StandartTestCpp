#include "View.h"
#include <gtc\matrix_transform.hpp>

namespace sqr{	
	View::View(std::string modelKeyName, const std::array<float, 4>& color) 
		: modelKeyName(modelKeyName), color(color) {
	}

	View::~View() {
	}
	
	std::string View::getModelKeyName() {
		return modelKeyName;
	}

	void View::setTransform(glm::mat4& val) {
		transform = val;
	}

	glm::mat4 View::getTransform() {
		return transform;
	}

	std::array<float, 4>& View::getColor() {
		return color;
	}

	void View::translate(float x, float y, float z) {
		transform = glm::translate(transform, glm::vec3{x, y, z});
	}

	void View::scale(float x, float y, float z) {
		transform = glm::scale(transform, glm::vec3{x, y, z});
	}
}
