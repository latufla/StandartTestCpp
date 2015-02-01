#include "Object.h"

namespace sqw {
	Object::Object(const glm::mat4& transform, const glm::vec2& speed) 
		: transform(transform), speed(speed) {
	}

	Object::~Object() {
	}

	glm::vec2& Object::getSpeed() {
		return speed;
	}

	glm::mat4& Object::getTransform() {
		return transform;
	}

	void Object::setTransform(const glm::mat4& val) {
		transform = val;
	}

}
