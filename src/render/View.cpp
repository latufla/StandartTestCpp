#include "View.h"
#include <gtc\matrix_transform.hpp>

namespace sqr{	
	View::View(std::string modelKeyName, const glm::vec4& color) 
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

	glm::vec4& View::getColor() {
		return color;
	}

	void View::translate(float x, float y, float z) {
		transform = glm::translate(glm::mat4{}, glm::vec3{x, y, z});
	}

	void View::scale(float x, float y, float z) {
		transform = glm::scale(transform, glm::vec3{x, y, z});
	}
}
